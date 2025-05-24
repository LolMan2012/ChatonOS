BOOTLOADER = BOOTX64.EFI
TARGET = ../iso/EFI/BOOT/$(BOOTLOADER)

EFIINC = /usr/include/efi
EFIINC_ARCH = /usr/include/efi/x86_64
EFILIB = /usr/lib

all: $(TARGET)

$(TARGET): bootloader.c
	mkdir -p ../iso/EFI/BOOT
	gcc -I$(EFIINC) -I$(EFIINC_ARCH) \
	    -fno-stack-protector -fpic -fshort-wchar \
	    -mno-red-zone -m64 -nostdlib \
	    -c bootloader.c -o bootloader.o

	ld -nostdlib -znocombreloc -T /usr/lib/elf_x86_64_efi.lds \
	    -shared bootloader.o -o $(TARGET) \
	    -L$(EFILIB) -lefi -lgnuefi

clean:
	rm -f *.o $(TARGET)

