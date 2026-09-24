# Avaliação

```javascript
var coin = createSprite(200,10); 
coin.setAnimation("coin_gold_1");
setCoin();

var bunny = createSprite(200,350);
bunny.setAnimation("bunny1_ready_1");

var score = 0;

function draw() {
  if (score >= 10) {
  drawSunshine();
  } else {
  drawSimpleBackground();
  }
  
  if(keyDown("left")){
    bunny.x = bunny.x - 5;
  }
  
  if(keyDown("right")){
    bunny.x = bunny.x + 5;
  }
  
  if(coin.y > 400){
    setCoin();
  }
  
  if (bunny.isTouching(coin)) {
  score = score + 1;
  setCoin();
  }

  textSize(20);
  text("Score: " + score, 10, 10, 100, 100);
  drawSprites();
}

function drawSimpleBackground() {
  background("white");
}

function drawSunshine() {
  background("skyblue");
  fill("yellow");
  ellipse(200,60,80,80);
  fill("green");
  rect(0,350,400,50);
  }

function setCoin(){
  coin.velocityY = 5;
  coin.y = 0;
  coin.x = randomNumber(0,400);
}
```

Comentário: Nesta atividade foram utilizadas funções para organizar diferentes partes do jogo. A função `setCoin()` controla o reposicionamento da moeda, enquanto `drawSimpleBackground()` e `drawSunshine()` alteram o cenário de acordo com a pontuação. Também foram utilizados controles por teclado, colisão entre sprites e uma variável de pontuação.

# Desafio a)

```javascript
function draw() {
  if (World.mouseY > 200) {
    drawScene1();
  } else {
    drawScene2();
  }
}

function drawScene1() {
  noStroke();
  background("midnightblue");

  fill("white");
  ellipse(80, 70, 60, 60);

  fill("midnightblue");
  ellipse(95, 60, 60, 60);

  fill("white");
  ellipse(150, 60, 5, 5);
  ellipse(220, 100, 5, 5);
  ellipse(300, 50, 5, 5);
  ellipse(350, 130, 5, 5);
  ellipse(180, 160, 5, 5);

  fill("darkgreen");
  rect(0, 330, 400, 70);

  fill("black");
  rect(270, 230, 80, 100);

  triangle(260, 230, 310, 180, 360, 230);

  fill("yellow");
  rect(285, 250, 20, 25);
  rect(320, 250, 20, 25);

  fill("brown");
  rect(305, 290, 20, 40);
}

function drawScene2() {
  noStroke();
  background("skyblue");

  fill("yellow");
  ellipse(80, 70, 70, 70);

  fill("white");
  ellipse(220, 80, 70, 40);
  ellipse(250, 70, 70, 50);
  ellipse(280, 80, 70, 40);

  fill("lightgreen");
  rect(0, 330, 400, 70);

  fill("orange");
  rect(270, 230, 80, 100);

  fill("red");
  triangle(260, 230, 310, 180, 360, 230);

  fill("lightblue");
  rect(285, 250, 20, 25);
  rect(320, 250, 20, 25);

  fill("brown");
  rect(305, 290, 20, 40);

  fill("green");
  ellipse(80, 290, 80, 90);

  fill("brown");
  rect(70, 310, 20, 40);
}
```

Comentário: Neste desafio foram criados dois cenários diferentes e a posição vertical do mouse é utilizada para escolher qual deles será exibido. Quando o cursor está em uma parte da tela aparece uma cena noturna e, na outra, uma cena diurna.

# Desafio b)

```javascript
function draw() {
  if (World.mouseY > 200) {
    drawNight();
  } else {
    drawDay();
  }
}

function drawDay() {
  noStroke();
  background("skyblue");

  fill("yellow");
  ellipse(70,70,70,70);

  fill("white");
  ellipse(230,70,70,40);
  ellipse(260,60,70,50);
  ellipse(290,70,70,40);

  fill("lightgreen");
  rect(0,330,400,70);

  drawHouse();
}

function drawNight() {
  noStroke();
  background("midnightblue");

  fill("white");
  ellipse(70,70,60,60);

  fill("midnightblue");
  ellipse(85,60,60,60);

  fill("white");
  ellipse(150,60,5,5);
  ellipse(210,100,5,5);
  ellipse(280,50,5,5);
  ellipse(350,110,5,5);

  fill("darkgreen");
  rect(0,330,400,70);

  drawHouse();
}

function drawHouse() {
  noStroke();

  fill("orange");
  rect(140,210,120,120);

  fill("red");
  triangle(125,210,200,150,275,210);

  fill("lightblue");
  rect(155,230,30,30);
  rect(215,230,30,30);

  fill("brown");
  rect(185,280,30,50);

  fill("yellow");
  ellipse(208,305,5,5);
}
```

Comentário: Neste desafio o código foi organizado em funções separadas para desenhar o cenário de dia, o cenário de noite e a casa. A posição do mouse define qual cenário será mostrado, enquanto a função `drawHouse()` é reaproveitada nos dois casos, evitando a repetição do mesmo código.
