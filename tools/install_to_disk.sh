mkdir -p /mnt/u
sudo mount $2 /mnt/u
cp -f $1 /mnt/u/EFI/BOOT/bootx64.efi
sudo umount  /mnt/u