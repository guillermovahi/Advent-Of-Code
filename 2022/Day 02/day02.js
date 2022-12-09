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
  let star1 = 0
  let star2 = 0
  // Loop through the array and assign top three biggest values
  while(++i < data.length) {
	let game = data[i].split(' ').map(String);
	star1 += chechkWinnerStar1(game[0], game[1]);
	star2 += chechkWinnerStar2(game[0], game[1]);

  }
	console.log(`First ⭐️: ${star1}`);
	console.log(`Second ⭐️: ${star2}`);
});

function chechkWinnerStar1(player1, player2){
	let points = 0
	if (player2 == 'X')
		points = 1;
	else if (player2 == 'Y')
		points = 2;
	else if (player2 == 'Z')
		points = 3;
	
	if (player1 == 'A' && player2 == 'X') // rock vs rock
		points += 3;
	else if (player1 == 'B' && player2 == 'Y') // paper vs paper
		points += 3;
	else if (player1 == 'C' && player2 == 'Z') // scissors vs scissors
		points += 3;
	else if (player1 == 'A' && player2 == 'Y') // rock vs paper
		points += 6;
	else if (player1 == 'B' && player2 == 'Z') // paper vs scissors
		points += 6;
	else if (player1 == 'C' && player2 == 'X') // scissors vs rock
		points += 6;
	return points	
}

function chechkWinnerStar2(player1, player2){
	let points = 0
	
	if (player2 == 'X')
		points = 0;
	else if (player2 == 'Y')
		points = 3;
	else if (player2 == 'Z')
		points = 6;	

	// rock = 1, paper = 2, scissors = 3
	if (player1 == 'A' && player2 == 'X') // rock vs lose (scissors)
		points += 3;
	else if (player1 == 'A' && player2 == 'Y') // rock vs draw (rock)
		points += 1;
	else if (player1 == 'A' && player2 == 'Z') // rock vs win (paper)
		points += 2;
	else if (player1 == 'B' && player2 == 'X') // paper vs lose (rock)
		points += 1;
	else if (player1 == 'B' && player2 == 'Y') // paper vs draw (paper)
		points += 2;
	else if (player1 == 'B' && player2 == 'Z') // paper vs win (scissors)
		points += 3;
	else if (player1 == 'C' && player2 == 'X') // scissors vs lose (paper)
		points += 2;
	else if (player1 == 'C' && player2 == 'Y') // scissors vs draw (scissors)
		points += 3;
	else if (player1 == 'C' && player2 == 'Z') // scissors vs win (rock)
		points += 1;
	return points	
}
