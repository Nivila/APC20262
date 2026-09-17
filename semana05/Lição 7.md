# Avaliação

```javascript
    var grass = createSprite(200,200);
    grass.setAnimation("floating_grass");
    var alien = createSprite(180,100);
    alien.setAnimation("alien");
    alien.scale = 1.3;
    var robot = createSprite(300,300);
    robot.setAnimation("robot");
    robot.scale = 0.2;
    var speech_left = createSprite(220,200);
    speech_left.setAnimation("speech_left");
    var speech_right = createSprite(250,40);
    speech_right.setAnimation("speech_right");
    drawSprites();
    textSize(12);
    text("Hello robot,", 220, 35);
    text("Can you see", 215, 47);
    text("me?", 250, 59);
    text("see", 200, 200);
    text("butterfly", 200, 220);
```

# Desafio a)

```javascript
    var sky = createSprite(200,200);
    sky.setAnimation("rainbow");
    drawSprites();
    textSize(50);
    fill("red");
    text("Rainbows", 30, 50);
    fill("orange");
    text("in the" , 70, 100);
    fill(rgb(randomNumber(0,255), randomNumber(0,255), randomNumber(0,255)))
    text("sky...", 110, 150);
 ```
# Desafio b)

```javascript
    fill("white");
    strokeWeight(3);
    stroke("black");
    textSize(20);
    text("Four score and seven years ago...", 30, 200);
```

# Desafio c)

```javascript
textSize(20);
fill("black");
text("Four score and seven years ago...", 10, 200);
```
# Desafio d)

```javascript
background("Lightblue");

// Sol
fill("yellow");
stroke("yellow");
ellipse(50, 50, 100, 100);

// Raios
line(70, 15, 90, 5);
line(85, 35, 110, 25);
line(90, 60, 120, 60);
line(75, 80, 95, 100);
line(50, 90, 50, 120);
line(25, 80, 10, 105);
line(10, 60, 0, 70);
line(15, 35, 0, 25);

// Mar
fill("blue");
stroke("blue");
line(400, 200, 0, 200);
rect(0, 200, 400, 200);

// sprites
var cloud = createSprite(200, 100);
cloud.setAnimation("cloud");
cloud.scale = 0.2;
var rainbow = createSprite(300, 80);
rainbow.setAnimation("rainbow");
rainbow.scale = 0.2;
var fish = createSprite(300, 280);
fish.setAnimation("fish");
fish.scale = 0.2;
var creature = createSprite(100, 300);
creature.setAnimation("creature");
creature.scale = 0.2;
var speech = createSprite(165, 220);
speech.setAnimation("speech");
speech.scale = 1.2;

function draw() {
  background("Lightblue");

  // Sol
  fill("yellow");
  stroke("yellow");
  ellipse(50, 50, 100, 100);

  // Mar
  fill("blue");
  stroke("blue");
  rect(0, 200, 400, 200);

  // Movimento aleatório
  cloud.x = randomNumber(180, 181);
  cloud.y = randomNumber(80, 81);

  rainbow.x = randomNumber(280, 281);
  rainbow.y = randomNumber(60, 61);

  fish.x = randomNumber(280, 281);
  fish.y = randomNumber(260, 261);

  creature.x = randomNumber(80, 85);
  creature.y = randomNumber(280, 285);

  drawSprites();

  // Bolhas
  fill("white");
  ellipse(350, 270, 20, 20);
  ellipse(360, 250, 15, 15);

  // Texto
  stroke("black");
  textSize(15);
  text("Hello, welcome stranger :)", 200, 15);

  // Fala
  fill("black");
  textSize(13);
  text("Hi, my name is", 122, 220);
  text("JACK", 145, 240);
}
```
