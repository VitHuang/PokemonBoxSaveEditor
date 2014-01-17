species = []
File.open("pokemon_game_indices.csv") {|f|
 f.each_line {|l|
  if l[/(\d+),7,(\d+)/]
   species[$2.to_i] = $1.to_i
  end
 }
}

for i in 0...species.length
 species[i] = 0 if !species[i]
end

File.open("speciesconversion.txt", "w") {|f|
 f.write(species.inspect)
}