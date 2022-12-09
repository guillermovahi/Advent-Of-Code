const fs = require('fs');

const data = fs.readFileSync('input2', 'utf8').split('\n').map((line) => {
	return [ , ] = line.split(' ')
})


console.log(data)


let mapState = [['.','.','.','.','.','.'],
				['.','.','.','.','.','.'],
				['.','.','.','.','.','.'],
				['.','.','.','.','.','.'],
				['H','.','.','.','.','.']]
let x = 0
let y = 0
let i = -1

let globalMap = []

//let aux = Array.from(dir)

/* while(++i < data.length){
	let direction = data[i][0]
	let distance = data[i][1]
	
	if(direction == 'R'){
		x += Number(distance)
	}else if(direction == 'L'){
		x -= Number(distance)
	}else if(direction == 'U'){
		y -= Number(distance)
	}else if(direction == 'D'){
		y += Number(distance)
	}

	let map = mapState.map((line) => line.slice())
	map[y][x] = 'X'
	globalMap.push(map)
} */
let mapaPruebas =  [['.','.','.','.','X','.']]

let eje = ['.','.','.','.','.','.']
mapaPruebas.push(eje)

let mapaPruebas2 = [['.','.','.','.','.','.'],
					['.','.','.','.','X','.']]

console.log(mapaPruebas)
console.log(mapaPruebas2)
console.log(mapaPruebas[0][4])
console.log(mapaPruebas2[1][4])

function createNewUpperLine(totalMap){ // returns a new totalMap with a new line
	let newLine = []
	let i = -1


}

//const array2D = data.map(line => line.split('').map(Number));

//console.log("First ⭐️: "+ star1)
//console.log("Second ⭐️: " + star2)