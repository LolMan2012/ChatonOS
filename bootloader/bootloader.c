#include <efi.h>
#include <efilib.h>

EFI_STATUS
EFIAPI
efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    InitializeLib(ImageHandle, SystemTable);
    Print(L"🐱 Bienvenue dans ChatonOS 64-bit (Bootloader UEFI) !\n");

    while (1); // Boucle infinie pour garder l'écran
    return EFI_SUCCESS;
}
