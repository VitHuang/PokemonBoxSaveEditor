File.open("save.gci"){|f|
 for i in 0...58
  f.seek(0x2040 + i * 0x2000)
  printf("%08X: ", f.pos)
  puts f.read(12).unpack("H*")
 end
}