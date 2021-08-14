#include <stdio.h>

#include "stdio.h"
#include <los.h>
#include <stdlib.h>

typedef struct {
    usize code;
    usize state;
} KeyEvent;

int __read_char_event(KeyEvent* key) {
    Event e;
    isize status;
    while (1) {
        while ((status = peek_event(&e))) {
            if (status != 1)
                return -1;

            if (e.type == EVENT_TYPE_KEY_PRESS) {
                key->code = e.param1;
                key->state = e.param2;
                return 0;
            }
        }
    }
}

char __translate_keycode(usize keycode, int caps) {
    if (caps) {
        switch (keycode) {
        case KEYCODE_SPACE:
            return ' ';
        case KEYCODE_QUOTE:
            return '"';
        case KEYCODE_COMMA:
            return ',';
        case KEYCODE_MINUS:
            return '_';
        case KEYCODE_PERIOD:
            return '.';
        case KEYCODE_FORWARD_SLASH:
            return '?';
        case KEYCODE_0:
            return ')';
        case KEYCODE_1:
            return '!';
        case KEYCODE_2:
            return '@';
        case KEYCODE_3:
            return '#';
        case KEYCODE_4:
            return '$';
        case KEYCODE_5:
            return '%';
        case KEYCODE_6:
            return '^';
        case KEYCODE_7:
            return '&';
        case KEYCODE_8:
            return '*';
        case KEYCODE_9:
            return '(';
        case KEYCODE_SEMI_COLON:
            return ':';
        case KEYCODE_EQUAL:
            return '+';
        case KEYCODE_OPEN_SQUARE_BRACKET:
            return '{';
        case KEYCODE_BACKSLASH:
            return '|';
        case KEYCODE_CLOSE_SQUARE_BRACKET:
            return '}';
        case KEYCODE_TICK:
            return '~';
        case KEYCODE_ENTER:
            return '\n';
        default:
            if ((char)keycode >= 'a' && (char)keycode <= 'z')
                return ((char)keycode) - 'a' + 'A';
            return (char)keycode;
        }
    } else {
        if (keycode == KEYCODE_ENTER)
            return '\n';
        return (char)keycode;
    }
}

int __read_char_console() {
    KeyEvent key;
    if (__read_char_event(&key) < 0)
        return -1;

    int caps_status = 0;
    if (key.state & KEY_STATE_CAPS_LOCK)
        caps_status = !caps_status;

    if ((key.state & KEY_STATE_LEFT_SHIFT) || (key.state & KEY_STATE_RIGHT_SHIFT))
        caps_status = !caps_status;

    char c = __translate_keycode(key.code, caps_status);

    if (console_write_ch(c) < 0)
        return -1;

    return c;
}

int fgetc(FILE* stream) {
    // Check for ungetc
    if (stream->ungetc != NULL) {
        UngetcNode* node = stream->ungetc;
        int ret = node->c;
        stream->ungetc = node->next;
        free(node);
        return ret;
    }

    if (stream->buffer_type == _IONBF) {
        switch (stream->type) {
        case STDIO_TYPE_CONSOLE: {
            int ret = __read_char_console();
            if (ret < 0)
                stream->flags |= FILE_FLAG_ERROR;
            return ret;
        }

        case STDIO_TYPE_FILE: {
            int ret;
            isize status = read_file(stream->descriptor, &ret, 1);
            if (status == -1) {
                stream->flags |= FILE_FLAG_EOF;
                return -1;
            } else if (status < 0) {
                stream->flags |= FILE_FLAG_ERROR;
                return -1;
            }

            return ret;
        }

        default:
            stream->flags |= FILE_FLAG_ERROR;
            return EOF;
        }
    } else {
        if (stream->buffer_offset == stream->buffer_length) {
            // Flush the current buffer
            if (fflush(stream) < 0)
                return -1;

            // Get next buffer
            switch (stream->type) {
            case STDIO_TYPE_CONSOLE: {
                int ret;
                while (1) {
                    ret = __read_char_console();

                    if (ret < 0) {
                        stream->flags |= FILE_FLAG_ERROR;
                        return -1;
                    }

                    stream->buffer[stream->buffer_length] = ret;
                    stream->buffer_length++;

                    if (ret == '\n' || stream->buffer_length == stream->buffer_capacity)
                        break;
                }
                break;
            }

            case STDIO_TYPE_FILE: {
                isize bytes_read = read_file(stream->descriptor, stream->buffer, stream->buffer_capacity);
                if (bytes_read >= 0) {
                    stream->buffer_length = bytes_read;
                    break;
                } else if (bytes_read == -1) {
                    stream->flags |= FILE_FLAG_EOF;
                    return -1;
                } else {
                    stream->flags |= FILE_FLAG_ERROR;
                    return -1;
                }
            }

            default:
                stream->flags |= FILE_FLAG_ERROR;
                return EOF;
            }
        }

        int ret = stream->buffer[stream->buffer_offset];
        stream->buffer_offset++;
        return ret;
    }
}