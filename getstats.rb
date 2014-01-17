stats = []
File.open("pokemon_stats.csv") {|f|
 f.each_line {|l|
  if l[/(\d+),(\d+),(\d+),.+/]
   stats[$1.to_i] = [] if !stats[$1.to_i]
   stats[$1.to_i][$2.to_i - 1] = $3
  end
 }
}

File.open("stats.txt", "w") {|f|
 for p in stats
  f.write(sprintf("%d,%d,%d,%d,%d,%d\n", p[0], p[1], p[2], p[5], p[3], p[4])) if p
 end
}