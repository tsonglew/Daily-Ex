const fs = require('fs');

function someAsyncOperation(callback) {
	fs.readFile(__filename, callback);
}

const timeoutScheduled = Date.now();

setTimeout(function () {
	const delay = Date.now() - timeoutScheduled;
	console.log(delay + 'ms have passed since I was scheduled!');
}, 100);

someAsyncOperation(function () {
	const startCallback = Date.now();
	while (Date.now() - startCallback < 10) {
		// do nothing
	}
});