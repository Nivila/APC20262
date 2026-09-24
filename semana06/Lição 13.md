# Avaliação

```javascript
var fish = createSprite(200,200);
fish.setAnimation("fishR");
fish.velocityX = 4;

function draw() {
  background("blue");

  // Se apertar a seta para a direita
  if (keyWentDown("right")) {
    fish.velocityX = 4;
    fish.setAnimation("fishR");
  }

  // Se chegar ao lado direito
  if (fish.x > 400) {
    fish.velocityX = -4;
    fish.setAnimation("fishL");
  }

  // Se chegar ao lado esquerdo
  if (fish.x < 0) {
    fish.velocityX = 0;
  }

  drawSprites();
}
```

Comentário: Nesta atividade foi utilizado o controle da velocidade horizontal de um sprite junto com estruturas condicionais. O peixe se movimenta para a direita, muda de direção ao chegar ao limite da tela e para quando alcança o lado esquerdo. Também foi utilizada a troca de animação para representar corretamente a direção do movimento.

# Desafio a)

```javascript
var alien = createSprite(50,200);
alien.setAnimation("alien");
alien.velocityX = 0;
alien.velocityY = -3;

function draw() {
  if (alien.y < 50) {
  alien.velocityX = 3;
  alien.velocityY = 0;
  }
  if (alien.x > 350) {
  alien.velocityX = 0; 
  alien.velocityY = 3;
  }
  if (alien.y > 350) {
  alien.velocityX = -3; 
  alien.velocityY = 0;
  }
  if (alien.x < 50) {
  alien.velocityX = 0;
  alien.velocityY = -3;
  }
  
  drawSprites();
}

var space = createSprite(200, 200);
space.setAnimation("space");
var flag1 = createSprite(50, 50);
flag1.setAnimation("yellow_flag");
var flag2 = createSprite(350, 50);
flag2.setAnimation("yellow_flag");
var flag3 = createSprite(350, 350);
flag3.setAnimation("yellow_flag");
var flag4 = createSprite(50, 350);
flag4.setAnimation("yellow_flag");
alien.depth=7;
```

Comentário: Neste desafio foram utilizadas as propriedades `velocityX` e `velocityY` para fazer o alienígena percorrer um caminho em formato quadrado. As estruturas condicionais verificam a posição do sprite e alteram sua direção ao chegar próximo de cada bandeira.

# Desafio b)

```javascript
var pencil = createSprite(65, 70);
pencil.setAnimation("pencil_right");
pencil.scale = 0.5;

pencil.velocityX = 3;
pencil.velocityY = 0;

function draw() {
  background("lightgray");

  fill("white");
  stroke("black");
  rect(45, 50, 290, 330);

  stroke("red");
  line(65, 50, 65, 380);

  fill("purple");
  textSize(20);
  text("COMECE DESENHANDO A MARGEM", 20, 35);

  if (pencil.x > 315) {
    if (pencil.velocityX > 0) {
      pencil.x = 315;
      pencil.velocityX = 0;
      pencil.velocityY = 3;
      pencil.setAnimation("pencil_down");
    }
  }
  if (pencil.y > 355) {
    if (pencil.velocityY > 0) {
      pencil.y = 355;
      pencil.velocityX = -3;
      pencil.velocityY = 0;
      pencil.setAnimation("pencil_left");
    }
  }
  if (pencil.x < 65) {
    if (pencil.velocityX < 0) {
      pencil.x = 65;
      pencil.velocityX = 0;
      pencil.velocityY = -3;
      pencil.setAnimation("pencil_up");
    }
  }
  if (pencil.y < 70) {
    if (pencil.velocityY < 0) {
      pencil.y = 70;
      pencil.velocityX = 3;
      pencil.velocityY = 0;
      pencil.setAnimation("pencil_right");
    }
  }

  drawSprites();

  fill("purple");
  textSize(15);
  text("SIGA OS CANTINHOS", 110, 400);
}
```

Comentário: Neste desafio foi criada uma movimentação automática para o lápis percorrer as bordas de uma folha. Foram utilizadas condições para identificar quando o sprite chega a cada canto, alterando suas velocidades e também sua animação de acordo com a nova direção.
