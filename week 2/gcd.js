/**
	Calculates greatest common divisor and prints it
*/

var readline = require('readline');

process.stdin.setEncoding('utf8');
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
});

function gcd(a, b) {
	while (b !== 0) {
		var c = a;
		a = b;
		b = c % b;
	}
	console.info(a);
	process.exit();
}

rl.on('line', readLine);

function readLine (line) {
	var a = parseInt(line.toString().split(' ')[0], 10);
	var b = parseInt(line.toString().split(' ')[1], 10);
	gcd(a, b);
}
