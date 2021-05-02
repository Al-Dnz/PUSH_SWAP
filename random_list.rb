min = ARGV[0].to_i || 0 
max = ARGV[1].to_i || 0
n = ARGV[2].to_i || 1
arr = (min..max).to_a.shuffle.first(n).join(" ");
puts arr;
