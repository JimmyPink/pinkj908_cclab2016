document.addEventListener('DOMContentLoaded', function(){ // wait until all our DOM elements are loaded before running script
 
 console.log("Ready!");
 
// the variables I hope to use
var colorPool = ["#000", "#ff0000", "#3e09f0"];  // "blue", "green", "white"
var seconds = 0;
var numOfColors = colorPool.length // name of the array for length of colors
var rotateIncrement = 0;
var rand = 0;
var yPos = 0;
var xPos = 0;
// 
//var holding the divs
var parentDiv = document.getElementById("mainDiv");
var cont1 = document.getElementById("cont1");
var cont2 = document.getElementById("cont2");
var cont3 = document.getElementById("cont3");

// function move(){
// 	for (i = 5; i<100; 1++){
// 		parentDiv xPos, yPos

	// }
// }
// variables for pulse function
var increment = 0;  // if nothing is said fter the number then  its px??
var direction = 0;
var maxSize = 100;
var minSize = 50;

//create timer function
function timer() {
 	setInterval(function(){
 		seconds += 1; // seconds = seconds + 1;
 		// console.log("Seconds:" + seconds);
 		if(seconds == 100) {
 			clearInterval(timer);
 		}
 		random = mod(seconds);
 		console.log("Random:" + random);
 		loadingScreen();

 		rotateIncrement = seconds * 45; 
 		parentDiv.style.transform = "rotate("+rotateIncrement+"deg)"; // we are affecting the css of our parentDiv. This outputs: rotate(0deg); where the number changes as the variable changes
 		console.log("Degrees: rotate(" + rotateIncrement + "deg)" );
 	}, 1000);
  }

// creates a function that randomizes numbers
function mod(num){
	return num%numOfColors;
}
// 	//function loading the changes to the div
	function loadingScreen() {
		cont1.styles.backgroundColor = colorPool[mod(random)];
		cont2.styles.backgroundColor = colorPool[mod(random+1)];
		cont3.styles.backgroundColor = colorPool[mod(random+2)];
// 		// cont1.styles.background = colorPool[mod(random+3)];
// 		// cont2.styles.background = colorPool[mod(random+4)];
// 		// cont3.styles.background = colorPool[mod(random+5)];

	}


timer();
// loadingScreen();
  });
