# Avaliação

```javascript
var backdrop = createSprite(200,200);
backdrop.setAnimation("sky");

var creature = createSprite(200,250);
creature.setAnimation("creature");
creature.scale = 0.2;

function draw() {
  // shake the sprite when the mouse is pressed
  if (mouseDown()) {
    creature.rotation = randomNumber(-5,5);
  }

  drawSprites();

  // display the text when the mouse is NOT pressed
  fill("black");
  textSize(40);
  text("Press the mouse to shake the creature.", 20, 50, 360, 100);
}
```

Comentário: Nesta atividade foi utilizada a interação com o mouse para modificar o comportamento de um sprite. Quando o botão do mouse é pressionado, o personagem recebe rotações aleatórias, criando um efeito de tremor na animação.

# Desafio a)

```javascript
var spiral = createSprite(100,200);
spiral.setAnimation("lollipop");

var spiral2 = createSprite(300,200);
spiral2.setAnimation("lollipop2");

function draw() {
  background("pink");

  if (mouseDown()) {
    spiral.scale = spiral.scale / 1.01;
    spiral.rotation = spiral.rotation + 3;

    spiral2.scale = spiral2.scale * 1.01;
    spiral2.rotation = spiral2.rotation - 3;
  } else {
    spiral.scale = spiral.scale * 1.01;
    spiral.rotation = spiral.rotation - 3;

    spiral2.scale = spiral2.scale / 1.01;
    spiral2.rotation = spiral2.rotation + 3;
  }

  drawSprites();
}
```

Comentário: Neste desafio foram aplicadas transformações de escala e rotação em dois sprites. O comportamento dos objetos se altera conforme o botão do mouse permanece pressionado ou não.

# Desafio b)

```javascript
var bee = createSprite(200, 200);
bee.setAnimation("bee");

function draw() {
  background("lightblue");

  bee.x = World.mouseX + randomNumber(-50,50);
  bee.y = World.mouseY + randomNumber(-50,50);

  drawSprites();
}
```

Comentário: Neste desafio foi utilizado o movimento do mouse para controlar a posição de uma abelha. Também foram aplicados valores aleatórios para criar um efeito de voo mais natural.

# Desafio c)

```javascript
var bee = createSprite(200, 200);
bee.setAnimation("bee");

function draw() {
  background("lightblue");

  bee.x = World.mouseX + randomNumber(-50,50);
  bee.y = World.mouseY + randomNumber(-50,50);

  drawSprites();
}
```

Comentário: Foi reforçada a utilização das coordenadas do mouse e da função `randomNumber()` para produzir movimentações dinâmicas do sprite.

# Desafio d)

```javascript
var salt = createSprite(200, 200);
salt.setAnimation("salt");
salt.rotation = 150;

function draw() {
  background("skyblue");

  // If mouseDidMove, rotate the salt shaker randomly to the left or right
  if (mouseDidMove()) {
    salt.rotation = randomNumber(130, 170);
  }

  drawSprites();
}
```

Comentário: Neste desafio foi utilizada a função `mouseDidMove()` para detectar movimentações do mouse. Sempre que o cursor é movido, o saleiro recebe uma rotação aleatória, simulando uma ação de chacoalhar.

# Desafio e)

```javascript
var balloon = createSprite(200, 300);
balloon.setAnimation("balloon");
balloon.scale = 0.5;

function draw() {
  background("lightblue");

  fill("lightgreen");
  rect(0, 350, 400, 50);

  fill("purple");
  textSize(30);
  text("Happy Badey!", 85, 70);

  fill("black");
  textSize(18);
  text("meus parabens!", 120, 110);

  if (mouseDown()) {
    balloon.y = balloon.y - 2;
  }

  if (balloon.y < 100) {
    balloon.y = 300;
  }

  drawSprites();
}
```

Comentário: Neste desafio foi criada uma animação interativa de aniversário. O balão sobe quando o botão do mouse é pressionado e retorna à posição inicial ao atingir determinada altura, criando um ciclo contínuo.

