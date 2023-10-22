
# nの素数判定をするには 2からroot(n)までで割ってみれば十分
def isPrime(num)
  return true if num == 2
  return false if num == 1 || num % 2 == 0

  (2..Math.sqrt(num).ceil).each do |i|
    return false if num % i == 0
  end

  return true
end


n = gets.to_i
count = 0
(0...n).each do |i|
  num = gets.to_i
  count += 1 if isPrime(num)
end
puts count