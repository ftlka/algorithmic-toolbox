/**
	Calculates n-th Fibonacci Number and prints it
*/

var readline = require('readline');

process.stdin.setEncoding('utf8');
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
});

function fib(n) {
	var phi = (1 + Math.sqrt(5)) / 2;
	var psi = (1 - Math.sqrt(5)) / 2;
	var result = (Math.pow(phi, n) - Math.pow(psi, n)) / Math.sqrt(5);
	console.info(Math.round(result));
	process.exit();
}

rl.on('line', readLine);

function readLine (line) {
	var num = parseInt(line.toString().split(' ')[0], 10);
	fib(num);
}
