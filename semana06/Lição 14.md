# Avaliação

```javascript
// create the sprites
var horse = createSprite(200, 150);
horse.setAnimation("horse");
var rainbow = createSprite(400, 370);
rainbow.setAnimation("rainbow");
rainbow.velocityX = -5;
rainbow.velocityY = -5;
rainbow.rotateToDirection = true;

function draw() {
  // draw the background
  background("skyblue");

  // change the horse to a unicorn when the rainbow touches it
  if (rainbow.isTouching(horse)) {
  horse.setAnimation("unicorn");
  }
  drawSprites();
}
```

Comentário: Nesta atividade foi utilizada a função `isTouching()` para detectar a colisão entre dois sprites. Quando o arco-íris toca o cavalo, sua animação é alterada para a de um unicórnio. Também foram utilizadas propriedades de velocidade e direção para movimentar o arco-íris pela tela.

# Desafio a)

```javascript
var roller = createSprite(200, 200);
roller.scale = 2;
roller.setAnimation("roller_1");
// Use .setCollider() with all 6 parameters.
roller.setCollider("rectangle", 0,-1,32,180,30);

roller.debug = true;
drawSprites();
```

Comentário: Neste desafio foi utilizada a função `setCollider()` para modificar a área de colisão do sprite. Também foi ativada a propriedade `debug`, permitindo visualizar o formato e a posição do colisor durante os testes.

# Desafio b)

```javascript
var points = 0;
var coin = createSprite(200, 100);
coin.setAnimation("coin");
var ghost = createSprite(200, 300);
ghost.setAnimation("ghost");

function draw() {
  if (ghost.isTouching(coin)) {
    points = points + 1;
    coin.x = randomNumber(50,350);
    coin.y = randomNumber(50,350);
  }
  
  background("lightblue");
  text("Points: " + points, 25, 25);
  if(keyDown("up")) {
    ghost.y = ghost.y - 5;
  }
  if(keyDown("down")) {
    ghost.y = ghost.y + 5;
  }
  if(keyDown("left")) {
    ghost.x = ghost.x - 5;
  }
  if(keyDown("right")) {
    ghost.x = ghost.x + 5;
  }
  drawSprites();
}
```

Comentário: Neste desafio foi criado um sistema de pontuação utilizando colisão entre sprites. O fantasma é controlado pelas setas do teclado e, ao tocar na moeda, a pontuação aumenta e a moeda é reposicionada aleatoriamente na tela.

# Desafio c)

```javascript
//GAME SETUP

var landscape = createSprite(200,200);
landscape.setAnimation("landscape");

var car = createSprite(10,330);
car.setAnimation("car");
car.scale = 0.3;

var vida = createSprite(randomNumber(20,350), 320);
vida.setAnimation("vida");
vida.rotation =(randomNumber(0,360));
vida.scale = 0.15;

var bomb1 = createSprite(randomNumber(0,400), 10);
bomb1.setAnimation("bomb");
bomb1.scale = 0.1;
bomb1.velocityY = 5;
var bomb2 = createSprite(randomNumber(0,400), 10);
bomb2.setAnimation("bomb");
bomb2.scale = 0.1;
bomb2.velocityY = 5;

var creature = createSprite(randomNumber(0,400), 10);
creature.setAnimation("creature");
creature.scale = 0.2;
creature.velocityY = 7;

var diamond = createSprite(randomNumber(20,350), 320);
diamond.setAnimation("diamond");
diamond.scale = 0.1;


var score = 0;
var health = 10;

function draw() {
  diamond.rotation = diamond.rotation +2;
  vida.rotation = vida.rotation +2;

  if (keyDown("right")) {
    if(score >=50) {
    car.setAnimation("carup");
    } else {
      car.setAnimation("car");
    }
    car.x = car.x + 10;
  }
  if (keyDown("left")) {
    if (score >= 50) {
    car.setAnimation("carup2");
    } else {
      car.setAnimation("car2");
    }
    car.x = car.x - 10;
  }
  if (bomb1.y > 400){
    bomb1.y = 0;
    bomb1.x = randomNumber(10,400);
  }
  if (bomb2.y > 400){
    bomb2.y = 0;
    bomb2.x = randomNumber(0,400);
  }
  if (creature.y > 400) {
  creature.y = 0;
  creature.x = randomNumber(0,400);
  }
  if (bomb1.isTouching(car)) {
    health = health - 4;
    car.setAnimation("explosão");
    bomb1.y = 0;
    bomb1.x = randomNumber(0,400);
  }
  if (bomb2.isTouching(car)) {
    health = health - 4;
    car.setAnimation("explosão");
    bomb2.y = 0;
    bomb2.x = randomNumber(0,400);
  }
  if (car.isTouching(diamond)) {
    score = score + 1;
    diamond.x = randomNumber(20,380);
  }
  if (car.isTouching(vida)) {
    health = health + 3;
    vida.x = randomNumber(20,380);
  }
  if (creature.isTouching(car)) {
  health = health - 6;
  car.setAnimation("explosão");

  creature.y = 0;
  creature.x = randomNumber(0,400);
  }
  if (health < 0) {
    health = 0;
  }
  if (health <=0) {
    bomb1.velocityY = 0;
    bomb2.velocityY = 0;
    creature.velocityY = 0;
    car.velocityX = 0;
    car.velocityY = 0;
    diamond.rotation = 0;
    landscape.setAnimation("gameover");
    background("black");
  }
  
  drawSprites();
  
  fill("white");
  textSize(20);
  text("Score:" + score, 10, 25);
  text("Health:" + health, 10, 50);
}
```

Comentário: Neste desafio foi desenvolvido um jogo utilizando movimentação, colisões, pontuação e sistema de vida. O carro pode ser controlado pelas setas do teclado, enquanto bombas e uma criatura funcionam como obstáculos que reduzem a vida. O diamante aumenta a pontuação e o item de vida recupera parte da saúde do jogador. Também foram utilizadas animações diferentes para representar colisões e uma tela de `game over` quando a vida chega a zero.
