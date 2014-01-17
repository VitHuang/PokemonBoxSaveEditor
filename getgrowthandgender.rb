growth = []
gender = []
File.open("pokemon_species.csv") {|f|
 f.each_line {|l|
  if l[/(\d+),.*?,.*?,.*?,.*?,.*?,.*?,.*?,(-?\d+),.*?,.*?,.*?,.*?,.*?,(\d+),.*?/]
   gender[$1.to_i] = $2.to_i
   growth[$1.to_i] = $3.to_i - 1
  end
 }
}

File.open("growth.txt", "w") {|f|
 f.write(growth[0,387].join("\n"))
}

File.open("gender.txt", "w") {|f|
 f.write(gender[0,387].join("\n"))
}