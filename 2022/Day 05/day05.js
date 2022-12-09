const fs = require('fs');

fs.readFile('./input', 'utf8', (err, data) => {
	// Error handling
	if (err) {
    console.error(err);
    return;
  }
  	// Split the input into an array of numbers
  	data = data.split('\n').map(String);
	let arrayOfStacks = []
  	let i = 8
	let j = 1
	
	// Create 8 stacks with input data
	while(j < data[8].length){
		let stack = new Stack()
		while(--i >= 0){
			if (data[i][j] !== ' ')
				stack.push(data[i][j])		
		}
		j += 4
		i = 8
		arrayOfStacks.push(stack)
	}
	i = 9
	j = 0
	let movements = []
	// Create arrays of movements from input data
	while(++i < data.length)
		movements[j++] = data[i].match(/[0-9]+/g)

	i = 9
	let k =0
	while(++i < data.length){
		j = -1
		let moves = parseInt(movements[k])
		while( ++j < moves){
			let temp = arrayOfStacks[parseInt(movements[k][1]) - 1].pop()
			arrayOfStacks[parseInt(movements[k][2]) - 1].push(temp)
		}
		k++
	}
	k = -1
	let star1 = ''
	while(++k < arrayOfStacks.length)
		star1 += arrayOfStacks[k].pop()
	console.log(`First ⭐️: ${star1}`);
});

fs.readFile('./input', 'utf8', (err, data) => {
	// Error handling
	if (err) {
    console.error(err);
    return;
  }
  	// Split the input into an array of numbers
  	data = data.split('\n').map(String);
	let arrayOfStacks = []
  	let i = 8
	let j = 1
	
	// Create 8 stacks with input data
	while(j < data[8].length){
		let stack = new Stack()
		while(--i >= 0){
			if (data[i][j] !== ' ')
				stack.push(data[i][j])		
		}
		j += 4
		i = 8
		arrayOfStacks.push(stack)
	}
	i = 9
	j = 0
	let movements = []
	// Create arrays of movements from input data
	while(++i < data.length)
		movements[j++] = data[i].match(/[0-9]+/g)

	i = 9
	let k =0
	while(++i < data.length){
		j = -1
		let moves = parseInt(movements[k])
		let temps = []
		while( ++j < moves)
			temps.push(arrayOfStacks[parseInt(movements[k][1]) - 1].pop())
		j = -1
		let tempsLength = temps.length
		while( ++j < moves)
			arrayOfStacks[parseInt(movements[k][2]) - 1].push(temps[-1 + tempsLength--])
		k++
	}
	k = -1
	let star2 = ''
	while(++k < arrayOfStacks.length)
		star2 += arrayOfStacks[k].pop()
  	console.log(`Second ⭐️: ${star2}`);
});

class Stack {
    constructor() {
        this.items = [];
    }
    push(item) {
        this.items.push(item)
    }
    pop() {
        if (this.isEmpty())
            throw new Error("Error popping")
        return this.items.pop()
    }
    isEmpty() {
        if (this.items.length === 0)
            return true
    }
    peek() {
        return this.items[this.items.length-1]
    }
}
