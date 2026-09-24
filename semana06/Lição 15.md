# Avaliação

```javascript
var rock = createSprite(200, 350);
rock.setAnimation("rock");
rock.velocityY =  -10;
rock.rotationSpeed = 2;

function draw() {
  background("skyblue");
  
  // update sprites
  rock.velocityY = rock.velocityY + 0.2;
  
  drawSprites();
}
```

Comentário: Nesta atividade foi trabalhado o conceito de aceleração por meio da alteração contínua da velocidade vertical do sprite. A pedra começa se movimentando para cima e, a cada repetição da função `draw()`, sua velocidade vertical aumenta, fazendo com que ela desacelere, pare e depois passe a cair. Também foi utilizada a propriedade `rotationSpeed` para manter a pedra girando durante o movimento.

# Desafio a)

```javascript
var plane = createSprite(50, 350);
plane.setAnimation("plane");
var rock = createSprite(150, 350);
rock.setAnimation("rock");
var rockdown = createSprite(350, 100);
rockdown.setAnimation("rock_down");

// You might want to change these 
plane.velocityY = -9;
plane.velocityX = 3;

function draw() {
  background("lightblue");
  
  // Make the Y velocity more downward
  plane.velocityY = plane.velocityY + 0.2;
  
  drawSprites();
}
```

Comentário: Neste desafio foi utilizado novamente o aumento gradual da velocidade vertical para criar um movimento curvo no avião. O sprite possui velocidade horizontal constante e uma velocidade vertical que é alterada continuamente, produzindo um efeito semelhante ao de uma trajetória sob ação da gravidade.

# Desafio b)

```javascript
var car = createSprite(200,350);
car.setAnimation("car");
car.velocityY = -15;

function draw() {
  background("forestgreen");
  fill("gray");
  rect(150,0,100,400);

  car.velocityY = car.velocityY + 0.4;

  if (car.velocityY > 0) {
    car.velocityY = 0;
  }

  drawSprites();
}
```

Comentário: Neste desafio foi aplicada uma alteração gradual na velocidade vertical do carro. O veículo inicialmente se movimenta para cima e sua velocidade vai diminuindo até chegar a zero. Uma estrutura condicional impede que a velocidade se torne positiva, fazendo com que o carro pare em vez de começar a se mover para baixo.

# Desafio c)

```javascript
var carroH = createSprite(200, 200);
carroH.setAnimation("car");
carroH.scale = 0.22;
carroH.velocityX = 3;

var carroV = createSprite(200, 0);
carroV.setAnimation("car");
carroV.scale = 0.22;
carroV.rotation = 90;
carroV.velocityY = 2;

function draw() {
  background("green");

  fill("gray");
  rect(150, 0, 100, 400);

  fill("gray");
  rect(0, 150, 400, 100);

  if (carroH.x > 350) {
    carroH.velocityX = -4;
  }

  if (carroH.x < 50) {
    carroH.velocityX = 4;
  }

  if (carroV.y > 350) {
    carroV.velocityY = -4;
  }

  if (carroV.y < 50) {
    carroV.velocityY = 4;
  }

  drawSprites();
}
```

Comentário: Neste desafio foram utilizados dois carros se movimentando em direções diferentes dentro de um cruzamento. As estruturas condicionais verificam os limites da tela e invertem as velocidades dos sprites, fazendo com que eles mudem de direção ao chegar às extremidades das pistas.
