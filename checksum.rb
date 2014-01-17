File.open("save.gci", "rb"){|f|
 checksum = 0
 f.seek(0x2044)
 for i in 0...0xFFC
  word = (f.getbyte << 8) + f.getbyte
  checksum += word
 end
 printf("%X\n", checksum & 0xFFFF)
}