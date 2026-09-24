# Avaliação

```javascript
// create sprites
var giraffe = createSprite(50, 50);
giraffe.setAnimation("giraffe");
giraffe.velocityX = 3;
var hippo = createSprite(50, 150);
hippo.setAnimation("hippo");
hippo.velocityX = 3;
var rabbit = createSprite(50, 250);
rabbit.setAnimation("rabbit");
rabbit.velocityX = 3;
var snake = createSprite(50, 350);
snake.setAnimation("snake");
snake.velocityX = 3;
var parrot = createSprite(350, 50);
parrot.setAnimation("parrot");
parrot.velocityX = -3;
var elephant = createSprite(350, 150);
elephant.setAnimation("elephant");
elephant.velocityX = -3;
var monkey = createSprite(350, 250);
monkey.setAnimation("monkey");
monkey.velocityX = -3;
var pig = createSprite(350, 350);
pig.setAnimation("pig");
pig.velocityX = -3;


function draw() {
  background("lightblue");
  giraffe.bounce(parrot);
  rabbit.collide(monkey);
  hippo.displace(elephant);
  snake.bounceOff(pig);
  drawSprites();
}
```

Comentário: Nesta atividade foram trabalhadas diferentes formas de interação entre sprites. Foram utilizadas as funções `bounce()`, `collide()`, `displace()` e `bounceOff()` para observar como cada tipo de colisão modifica o movimento e o comportamento dos personagens.

# Desafio a)

```javascript
// Create Gold Coin
var goldCoin = createSprite(51,50);
goldCoin.setAnimation("gold_coin");
goldCoin.velocityX = 2;
goldCoin.velocityY = 2;
goldCoin.debug = true;

// Create Silver Coin
var silverCoin = createSprite(350,350);
silverCoin.setAnimation("silver_coin");
silverCoin.velocityX = -2;
silverCoin.velocityY = -2;
silverCoin.debug = true;

function draw() {
  background("darkgreen");

  // Sprite Interactions
  goldCoin.bounce(silverCoin);
  
  drawSprites();
}
```

Comentário: Neste desafio foi utilizada a função `bounce()` para fazer com que duas moedas mudem de direção quando colidem. A propriedade `debug` também foi ativada para visualizar as áreas de colisão dos sprites durante o teste.

# Desafio b)

```javascript
var goldCoin = createSprite(49,50);
goldCoin.setAnimation("gold_coin");
goldCoin.velocityX = 2;
goldCoin.velocityY = 2;
goldCoin.debug = true;
goldCoin.setCollider("circle");

var silverCoin = createSprite(350,350);
silverCoin.setAnimation("silver_coin");
silverCoin.velocityX = -2;
silverCoin.velocityY = -2;
silverCoin.debug = true;
silverCoin.setCollider("circle");

function draw() {
  goldCoin.bounce(silverCoin);
  
  background("darkgreen");
  drawSprites();
}
```

Comentário: Neste desafio foram ajustados os colisores das moedas utilizando `setCollider("circle")`. Com isso, as áreas de colisão ficaram mais próximas do formato dos sprites, melhorando o comportamento da função `bounce()` durante o contato entre eles.

# Desafio c)

```javascript
var basketball = createSprite(100, 0);
basketball.setAnimation("basketball");
basketball.bounciness = 0.8;

var soccerball = createSprite(225, 0);
soccerball.setAnimation("soccerball");
soccerball.bounciness = 0.5;

var poolball = createSprite(325, 0);
poolball.setAnimation("poolball");
poolball.bounciness = 0.4;

var wood = createSprite(200, 375);
wood.setAnimation("floor");


function draw() {
  background("skyblue");
  
  basketball.bounceOff(wood);
  soccerball.bounceOff(wood);
  poolball.bounceOff(wood);
  
  basketball.velocityY = basketball.velocityY + 0.2;
  soccerball.velocityY = soccerball.velocityY + 0.2;
  poolball.velocityY = poolball.velocityY + 0.2;
  
  drawSprites();
}
```

Comentário: Neste desafio foram utilizados valores diferentes para a propriedade `bounciness` de três bolas. Também foi aplicada uma aceleração vertical para simular a gravidade, enquanto a função `bounceOff()` permite que as bolas ququem ao atingir o piso.

# Desafio d)

```javascript
var player = createSprite(200,100);
player.setAnimation("fly_bot");
player.scale = 0.8;

var target = createSprite(randomNumber(0,400), randomNumber(0,400));
target.setAnimation("coin");

var obstacleX = createSprite(-50, randomNumber(50,350));
obstacleX.setAnimation("rock");
obstacleX.velocityX = 4;

var obstacleY = createSprite(randomNumber(50,350), -50);
obstacleY.setAnimation("rock");
obstacleY.velocityY = 4;

function draw() {
  background("lightblue");

  player.velocityY = player.velocityY + 0.5;

  if (obstacleX.x > 450) {
    obstacleX.x = -50;
    obstacleX.y = randomNumber(50,350);
  }

  if (obstacleY.y > 450) {
    obstacleY.y = -50;
    obstacleY.x = randomNumber(50,350);
  }

  if (keyDown("up")) {
    player.velocityY = -8;
  }

  if (keyDown("left")) {
    player.velocityX = player.velocityX - 0.3;
  }

  if (keyDown("right")) {
    player.velocityX = player.velocityX + 0.3;
  }

  if (player.isTouching(target)) {
    target.x = randomNumber(0,400);
    target.y = randomNumber(0,400);
  }

  obstacleX.displace(player);
  obstacleY.displace(player);

  drawSprites();

  if (player.x < -50 ||
      player.x > 450 ||
      player.y < -50 ||
      player.y > 450) {

    background("black");
    fill("green");
    textSize(50);
    text("Game Over!", 50, 200);
  }
}
```

Comentário: Neste desafio foi desenvolvido um pequeno jogo com movimentação por teclado, gravidade, coleta de moeda e obstáculos. As pedras utilizam `displace()` para empurrar o jogador, enquanto a moeda muda de posição quando é coletada. Também foi criada uma condição de `Game Over` quando o personagem sai dos limites da tela.
