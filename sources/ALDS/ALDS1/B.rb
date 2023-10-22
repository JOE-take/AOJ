def gcd(a, b)
  a, b = b, a if a < b
  if a % b == 0
    return b
  else
    gcd(b, a%b)
  end
end

args = gets.split(' ')
a = args[0].to_i
b = args[1].to_i

puts gcd(a, b)