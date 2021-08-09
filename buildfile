name = c
type = library
language = c
objects = {
    crt0.o = {
        source = crt0.asm
        language = asm
    }

    crti.o = {
        source = crti.asm
        language = asm
    }

    crtn.o = {
        source = crtn.asm
        language = asm
    }
}