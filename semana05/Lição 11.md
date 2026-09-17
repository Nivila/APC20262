# Avaliação

```javascript
var backdrop = createSprite(200,200);
backdrop.setAnimation("rainbow");

var flyer = createSprite(200,200);
flyer.setAnimation("wing_bot");

function draw() {
  // move left when the left arrow is pressed
  if (keyDown("up")) {
    flyer.y = flyer.y - 2;
  }

  // move right when the right arrow is pressed
  if (keyDown("down")) {
    flyer.y = flyer.y + 2;
  }

  // move up when the up arrow is pressed
  if (keyDown("left")) {
    flyer.x = flyer.x - 2;
  }

  // move down when the down arrow is pressed
  if (keyDown("right")) {
    flyer.x = flyer.x + 2;
  }

  drawSprites();
}
```

Comentário: Nesta atividade foi utilizado o teclado para controlar o movimento de um sprite em diferentes direções. Foram aplicadas estruturas condicionais associadas às teclas direcionais para alterar as coordenadas do personagem na tela.

# Desafio a)

```javascript
var clicks = 0;

function draw() {
  // add clicks when the space bar is pressed
  if (keyWentDown("space")) {
    clicks = clicks + 1;
  }

  background("white");
  textSize(50);
  text(clicks, 165, 175, 70, 50);
}
```

Comentário: Neste desafio foi criado um contador de pressionamentos da tecla espaço. Foi utilizada uma variável para armazenar a quantidade de cliques e a função `keyWentDown()` para detectar cada novo acionamento da tecla.

# Desafio b)

```javascript
var bug = createSprite(200, 200);
bug.setAnimation("fly");

function draw() {
  // Draw Background
  background("white");
  
  // Update Values
  if(keyDown("up")){
    bug.rotation = 90;
    bug.y = bug.y - 5;
  }

  if(keyDown("down")){
    bug.rotation = 270;
    bug.y = bug.y + 5;
  }

  if(keyDown("left")){
    bug.rotation = 0;
    bug.x = bug.x - 5;
  }

  if(keyDown("right")){
    bug.rotation = 180;
    bug.x = bug.x + 5;
  }

  // Draw Animations
  drawSprites();
}
```

