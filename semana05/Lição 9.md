# Avaliação

```javascript
var orangeFish = createSprite(400, randomNumber(0, 100));
orangeFish.setAnimation("orange_fish");
var blueFish = createSprite(250, randomNumber(0, 200));
blueFish.setAnimation("blue_fish");
var greenFish = createSprite(300, randomNumber(200, 300));
greenFish.setAnimation("green_fish");
var bubbleY = 400;
var bubbleY1 = 400;

function draw() {
  // Draw Background
  background("navy");
  
  // Update Values
  if (keyDown("left")) {
    orangeFish.x = orangeFish.x - 2;
    blueFish.x = blueFish.x - 4;
    greenFish.x = greenFish.x - 2;
  }
  
  // Bolha
  noFill();
  stroke("white");
  strokeWeight(2);
  ellipse(200, bubbleY, 25, 25);
  ellipse(150, bubbleY1, 25, 25);

  // Counter Pattern
  bubbleY = bubbleY - 2;
  bubbleY1 = bubbleY - 15;
  
  // Draw Animations
  drawSprites();
}
```

Comentário: Nesta atividade foi criado um cenário submarino contendo diferentes peixes. Foi utilizada a função `keyDown()` para movimentar os sprites quando a tecla de direção é pressionada. Também foi aplicado o padrão contador para criar a animação das bolhas subindo na tela.

# Desafio a)

```javascript
var orangeFish = createSprite(400, randomNumber(0, 100));
orangeFish.setAnimation("orange_fish");
var blueFish = createSprite(250, randomNumber(0, 200));
blueFish.setAnimation("blue_fish");
var greenFish = createSprite(300, randomNumber(200, 300));
greenFish.setAnimation("green_fish");
var bubbleY = 400;
var bubbleY1 = 400;

function draw() {
  // Draw Background
  background("navy");
  
  // Update Values
  if (keyDown("left")) {
    orangeFish.x = orangeFish.x - 2;
    blueFish.x = blueFish.x - 4;
    greenFish.x = greenFish.x - 2;
  }
  
  // Bolha
  noFill();
  stroke("white");
  strokeWeight(2);
  ellipse(200, bubbleY, 25, 25);
  ellipse(150, bubbleY1, 25, 25);

  // Counter Pattern
  bubbleY = bubbleY - 2;
  bubbleY1 = bubbleY - 15;
  
  // Draw Animations
  drawSprites();
}
```

Comentário: O desafio reforçou a utilização de sprites, controle por teclado e animações utilizando o laço `draw()`. Também foi trabalhado o padrão contador para movimentação vertical das bolhas.

# Desafio b)

```javascript
var orangeFish = createSprite(400, randomNumber(0, 100));
orangeFish.setAnimation("orange_fish");
var blueFish = createSprite(250, randomNumber(0, 200));
blueFish.setAnimation("blue_fish");
var greenFish = createSprite(300, randomNumber(200, 300));
greenFish.setAnimation("green_fish");
var bubbleY = 400;
var bubbleY1 = 400;

function draw() {
  // Draw Background
  background("navy");
  
  // Update Values
  if (keyDown("left")) {
    orangeFish.x = orangeFish.x - 2;
    blueFish.x = blueFish.x - 4;
    greenFish.x = greenFish.x - 2;
  }
  
  // Bolha
  noFill();
  stroke("white");
  strokeWeight(2);
  ellipse(200, bubbleY, 25, 25);
  ellipse(150, bubbleY1, 25, 25);

  // Counter Pattern
  bubbleY = bubbleY - 2;
  bubbleY1 = bubbleY - 15;
  
  // Draw Animations
  drawSprites();
}
```

Comentário: Neste desafio foi praticada novamente a movimentação dos peixes e a atualização contínua dos objetos na tela, reforçando os conceitos de repetição e animação.

# Desafio c)

```javascript
var orangeFish = createSprite(100, 100);
orangeFish.setAnimation("orange_fish");
orangeFish.scale = 0.3;

var blueFish = createSprite(250, 200);
blueFish.setAnimation("blue_fish");
blueFish.scale = 0.3;

var bubbleY = 400;

function draw() {
  background("navy");

  fill("gold");
  rect(0, 350, 400, 50);
  
  // Movimento dos peixes
  orangeFish.x = orangeFish.x + 2;
  blueFish.y = blueFish.y + randomNumber(-2, 2);

  // Bolha
  noFill();
  stroke("white");
  strokeWeight(2);
  ellipse(100, bubbleY, 25, 25);
  ellipse(150, bubbleY, 25, 25);

  bubbleY = bubbleY - 2;

  fill("white");
  textSize(20);
  text("DISCOVERY :)", 100, 30);

  drawSprites();
}
```

Comentário: Neste desafio foi criado um ambiente submarino com peixes em movimento e bolhas animadas. Foram utilizados movimento automático, números aleatórios e exibição de texto para enriquecer a cena desenvolvida.
