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
  let product = 1;
  const mu = 1000000007;
  while (n) {
    product *= n;
    product = product % mu;
    n--;
  }
  return product % mu;
};

const sum = (a, b) => {
  const mu = 1000000007;
  a = a % mu;
  b = b % mu;
  return (a + b) % mu;
};

function main(input) {
  const a = Number(stdin_input.split("\n")[0]);

  const mu = 1000000007;

  let result = a;
  const n = (a + 1) / 2;

  let i,
    k = 0; //simple counter

  for (i = 2; i <= n; i++) {
    let inc = a - i;
    let fact = factorial(i);
    while (inc > 0) {
      result += (inc * fact) % mu;
      inc--;
    }
  }

  result = result % mu;

  process.stdout.write(result + "\n");
}
