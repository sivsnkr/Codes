process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});
 
function main(input) {
    var test_cases = input.split("\n").slice(1);
    var indexes = [];
    
    test_cases.forEach(test_case => {
        var [index, N] = test_case.split(" ").map(x => parseInt(x, 10));
        // if in center, 100% chance it will go to the sides (ends at 0 or 2, lower is 0)
        // if on sides, 100% chance it will go to the center (ends at 1)
        if (index === 2 && N === 0) {
            indexes.push(2);
        } else {
            var original_index = index % 2;
            var index_changed = N % 2;
            
            indexes.push(original_index ^ index_changed);
        }
    })
    
    process.stdout.write(indexes.join("\n"));       // Writing output to STDOUT
}