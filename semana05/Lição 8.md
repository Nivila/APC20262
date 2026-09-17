# Avaliação

```javascript
//1) Add the draw loop block to the bottom of this program.
//2) Move any blocks that need to be inside the draw loop.

var salt = createSprite(200,200);
salt.setAnimation("salt");

function draw() {
  background("skyblue");
  salt.rotation = 180;
  salt.y = 200 + randomNumber(-1,1);
  drawSprites();
}
```

Comentário: Nesta atividade foi utilizada a função `draw()` para criar uma animação contínua. O sprite do sal foi rotacionado e recebeu uma pequena movimentação aleatória no eixo Y, produzindo um efeito visual de vibração.

# Desafio a)

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

Comentário: Neste desafio foi criada uma cena animada contendo mar, sol, nuvem, arco-íris, peixe e personagem. Foram utilizados sprites, textos, formas geométricas e movimentação aleatória para tornar o cenário mais dinâmico.

# Desafio b)

```javascript
background("lightblue");

var fish = createSprite(300, 280);
fish.setAnimation("fish");
fish.scale = 0.2;

var creature = createSprite(100, 300);
creature.setAnimation("creature");
creature.scale = 0.2;

var cloud = createSprite(200, 100);
cloud.setAnimation("cloud");
cloud.scale = 0.2;

function draw() {
  background("lightblue");

  // Sol
  fill("yellow");
  ellipse(350, 50, 80, 80);

  // Mar
  fill("blue");
  rect(0, 200, 400, 200);

  // Movimento dos personagens
  fish.x = fish.x + randomNumber(-3, 3);
  fish.y = fish.y + randomNumber(-2, 2);

  creature.x = creature.x + randomNumber(-2, 2);
  creature.y = creature.y + randomNumber(-2, 2);

  cloud.x = cloud.x + randomNumber(-1, 1);

  drawSprites();
}
```

Comentário: Neste desafio foi desenvolvida uma animação utilizando movimentação aleatória dos sprites. O peixe, a criatura e a nuvem se deslocam continuamente pela tela, simulando movimento dentro do cenário.
