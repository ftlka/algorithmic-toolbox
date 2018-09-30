var readline = require('readline');

process.stdin.setEncoding('utf8');
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
});

function alg(arr) {
	var firstIdx = 0;
	var secondIdx;
	for (var i = 1; i < arr.length; i++) {
		if (arr[i] > arr[firstIdx]) {
			firstIdx = i;
		}
	}
	for (var i = 0; i < arr.length; i++) {
		if (i !== firstIdx && (arr[i] > arr[secondIdx] || !secondIdx)) {
			secondIdx = i;
		}
	}
	console.info(arr[firstIdx] * arr[secondIdx]);
	process.exit();
}

rl.on('line', readLine);
var num;

function readLine (line) {
	if (!num) {
		num = parseInt(line.toString().split(' ')[0], 10);
	} else {
		alg(line.toString().split(' ').map(Number));
	}
}
