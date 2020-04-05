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
  let inputString = stdin_input.split(" ");
  let n = Number(inputString[0]);
  let partition = [];
  let i; //simple counter
  let arr = [];
  for (i = 0; i < n; i++) {
    arr[i] = Number(inputString[1][i]);
  }

  let rightOne = [];
  let value = 0;
  for (i = n - 1; i >= 0; i--) {
    if (arr[i] === 1) {
      value++;
    }
    rightOne[i] = value;
  }

  let leftOne = [];
  value = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] === 1) {
      value++;
    }
    leftOne[i] = value;
  }

  let independentPart = 0;
  for (i = 0; i < n; i++) {
    if (arr[i + 1] !== 0)
      if (rightOne[i] > leftOne[i]) {
        if (partition.length === 0) {
          partition[0] = i;
        } else {
          partition.push(i);
        }
        independentPart++;
      }
  }

  for (i = partition[0] + 1; i < n; i++) {
    if (arr[i + 1] !== 0 && rightOne[i] <= leftOne[i]) {
      if (
        leftOne[i] - leftOne[partition[partition.length - 1]] <=
        rightOne[i] - 1
      ) {
        partition.push(i);
      }
    }
  }

  let partitionLength = [];
  partitionLength[0] = partition[0] + 1;
  for (i = 1; i < partition.length; i++) {
    partitionLength[i] = partition[i] - partition[i - 1];
  }
  partitionLength[partition.length] = n - 1 - partition[partition.length - 1];

  let valueLength = [];
  valueLength[0] = leftOne[partition[0]];
  for (i = 1; i < partition.length; i++) {
    valueLength[i] = leftOne[partition[i]] - leftOne[partition[i - 1]];
  }

  valueLength[partition.length] =
    leftOne[partition.length] - leftOne[[partition.length - 1]];

  let sumLength = [];
  for (i = 0; i < valueLength.length; i++) {
    sumLength[i] = valueLength[i] + partitionLength[i];
  }

  let partitionLeftone = [],
    partitionRightone = [];
  value = 0;
  for (i = 0; i < valueLength.length; i++) {
    value += sumLength[i];
    partitionRightone[i] = value;
  }
  value = 0;
  for (i = valueLength.length - 1; i >= 0; i--) {
    value += sumLength[i];
    partitionLeftone[i] = value;
  }

  let counter = 0;
  for (i = 0; i < valueLength.length; i++) {
    if (partitionLeftone[i] < partitionRightone[i]) {
      counter++;
    }
  }

  counter++;
  counter = counter % 1000000007;
  process.stdout.write(counter + "\n");
}
