.section .test
.global __custom_crtn_marker
__custom_crtn_marker:
    nop

.section .init
    pop %ebp
    ret

.section .fini
    pop %ebp
    ret
