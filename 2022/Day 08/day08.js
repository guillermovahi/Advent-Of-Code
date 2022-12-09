const fs = require('fs');

const data = fs.readFileSync('input', 'utf8').split('\n')
const array2D = data.map(line => line.split('').map(Number));
let i = 0;
let j = 0;
let star1 = array2D.length * array2D[0].length - ((array2D.length - 2) * (array2D[0].length - 2)) 
const size = array2D.length
let star2 = 0

while(++i < size - 1){
	while(++j < size - 1){
		let total = [checkUp(i,j), checkDown(i,j), checkLeft(i,j), checkRight(i,j)]
		let aux = total[0][1] * total[1][1] * total[2][1] * total[3][1]
		if ( total[0][0] || total[1][0] || total[2][0] || total[3][0])
			star1++
		star2 = aux > star2 ? aux : star2
	}
	j = 0
}

function checkUp(i, j){
	let noBigger = true
	let treesAvailable = 0
	let k = 0
	let iFix = i
	let firsTime = false
	while(i > 0){
		k++
		if(array2D[iFix][j] <= array2D[i - 1][j])
			noBigger = false
		if(!noBigger && !firsTime){
			treesAvailable = k
			firsTime = true
		}
		i = i -1
	}
	if (noBigger)
		treesAvailable = k
	return [noBigger, treesAvailable]
}

function checkDown(i, j){
	let noBigger = true
	let treesAvailable = 0
	let k = 0
	let iFix = i
	let firsTime = false
	while(i < size - 1){
		k++
		if(array2D[iFix][j] <= array2D[i + 1][j])
			noBigger = false
		if(!noBigger && !firsTime){
			treesAvailable = k
			firsTime = true
		}
		i = i + 1
	}
	if (noBigger)
		treesAvailable = k
	return [noBigger, treesAvailable]
}

function checkLeft(i, j){
	let noBigger = true
	let treesAvailable = 0
	let k = 0
	let jFix = j
	let firsTime = false
	while(j > 0){
		k++
		if(array2D[i][jFix] <= array2D[i][j - 1])
			noBigger = false
		if(!noBigger && !firsTime){
			treesAvailable = k
			firsTime = true
		}
		j = j - 1 
	}
	if (noBigger)
		treesAvailable = k
	return [noBigger, treesAvailable]
}

function checkRight(i, j){
	let noBigger = true
	let treesAvailable = 0
	let k = 0
	let jFix = j
	let firsTime = false
	while(j < size - 1){
		k++
		if(array2D[i][jFix] <= array2D[i][j + 1])
			noBigger = false
		if(!noBigger && !firsTime){
			treesAvailable = k
			firsTime = true
		}
		j = j + 1
	}
	if (noBigger)
		treesAvailable = k
	return [noBigger, treesAvailable]
}


console.log("First ⭐️: "+ star1)
console.log("Second ⭐️: " + star2)