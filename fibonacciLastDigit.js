/**
	Calculates n-th Fibonacci Number's last digit and prints it
*/

var readline = require('readline');

process.stdin.setEncoding('utf8');
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
});

function fibLastDigit(n) {
	const arr = [1, 1];
	for (let i = 2; i < n; i++) {
		arr.push((arr[i - 1] + arr[i - 2]) % 10);
	}
	console.info(arr[arr.length - 1]);
	process.exit();
}

rl.on('line', readLine);

function readLine (line) {
	var num = parseInt(line.toString().split(' ')[0], 10);
	fibLastDigit(num);
}
