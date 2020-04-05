process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";

process.stdin.on("data", function(input) {
  stdin_input += input;
});

process.stdin.on("end", function() {
  main(stdin_input);
});

function main(input) {
  const inputString = stdin_input.split("\n");
  const n = Number(inputString[0]);

  process.stdout.write(typeof a[0] + " " + typeof p[0] + ".\n");
}
