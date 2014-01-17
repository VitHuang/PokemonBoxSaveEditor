names = []
File.open("move_names.csv") {|f|
 f.each_line {|l|
  if l[/(\d+),9,(.+)/]
   names[$1.to_i] = $2
  end
 }
}

File.open("movenames.txt", "w") {|f|
 f.write(names.join("\n"))
}