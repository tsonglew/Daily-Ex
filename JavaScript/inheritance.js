'use strict';

function Graph() {
	this.vertices = [];
	this.edges = [];
}

Graph.prototype = {
	addVertex: function (v) {
		this.vertices.push(v);
	}
};

var g = new Graph();

console.log(g.hasOwnProperty('vertices'));
console.log(g.hasOwnProperty('edges'));
console.log(g.hasOwnProperty('addVertex'));
console.log(g.__proto__.hasOwnProperty('addVertex'));

class Polygon {
	constructor (height, width) {
		this.height = height;
		this.width = width;
	}
}

class Square extends Polygon {
	constructor (sideLength) {
		super(sideLength, sideLength);
	}
	get area () {
		return this.height * this.width;
	}
	set sideLength (newLength) {
		this.height = newLength;
		this.width = newLength;
	}
}

var square = new Square(2);
console.log(square.area);