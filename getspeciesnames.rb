names = []
File.open("pokemon_species_names.csv") {|f|
 f.each_line {|l|
  if l[/(\d+),9,(.+),.+/]
   names[$1.to_i] = $2
  end
 }
}

File.open("speciesnames.txt", "w") {|f|
 f.write(names.join("\n"))
}