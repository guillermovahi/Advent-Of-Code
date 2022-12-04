const fs = require('fs');

fs.readFile('./input', 'utf8', (err, data) => {
	// Error handling
	if (err) {
    console.error(err);
    return;
  }
  // Split the input into an array of numbers
  data = data.split('\n').map(String);

  // Variable declaration
  let i = -1;
  let j = -1
  let star1 = 0
  let star2 = 0
  let letter = ''
  // Loop through the array and assign top three biggest values
  while(++i < data.length) {
	//slice the string into two equal parts
	let department1 = data[i].slice(0, data[i].length/2);
	let department2 = data[i].slice(data[i].length/2, data[i].length);
 	while(++j < department1.length){
		if (department2.indexOf(department1[j]) !== -1){
			letter = department1[j];
			j = -1;
			star1 += assignPriority(letter)
			break
		}
	}
	}
	i = -1
	j = -1
	while(++i < data.length) {
		let department1 = data[i++]
		let department2 = data[i++]
		let department3 = data[i]
		 while(++j < department1.length){
			if ((department2.indexOf(department1[j]) !== -1) && (department3.indexOf(department1[j]) !== -1)){
				letter = department1[j];
				j = -1;
				star2 += assignPriority(letter)
				break
			}
		}
	}
	console.log(`First ⭐️: ${star1}`); //7756 no es -> 7746
 	console.log(`Second ⭐️: ${star2}`);
 });


function assignPriority(letter){
	//assign priorities 1 through 26 to Lowercase letter types a through z
	let i = 0
	let alpha = Array.from(Array(26)).map((e, j) => j + 65 + 32);
	let alphabet = alpha.map((x) => String.fromCharCode(x));
	while(++i < 27){
		if (letter == alphabet[i-1])
			return i 
	}
	i = 0
	alpha = Array.from(Array(26)).map((e, k) => k + 65);
	alphabet = alpha.map((x) => String.fromCharCode(x));
	while(++i < 27){
		if (letter === alphabet[i-1])
			return i + 26
	}
}