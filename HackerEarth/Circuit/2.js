process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";

process.stdin.on("data", function(input) {
  stdin_input += input;
});

process.stdin.on("end", function() {
  main(stdin_input);
});

const factorial = n => {
  let mu = 1000000007;
  let fact = 1;
  while (n > 0) {
    fact *= n;
    fact = fact % mu;
    n--;
  }
  return fact % mu;
};

function main(input) {
  const inputString = stdin_input.split(" ");
  let [n, m] = inputString;
  n = Number(n);
  m = Number(m);

  const result = factorial(m);

  process.stdout.write(result + "\n");
}
