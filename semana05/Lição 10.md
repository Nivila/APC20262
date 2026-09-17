# Avaliação

```javascript
var backdrop = createSprite(200,200);
backdrop.setAnimation("sci_fi");

var dinosaur = createSprite(200, 350);
dinosaur.scale = 0.2;
dinosaur.setAnimation("tyrannosaurus");

function draw() {
  // move the dinosaur up
  dinosaur.y = dinosaur.y - 5;

  // if it gets to the sky, turn it into a pterodactyl
  if (dinosaur.y < 200) {
    dinosaur.setAnimation("pterodactyl");
  }

  // draw everything
  drawSprites();
}
```

Comentário: Nesta atividade foi utilizada uma estrutura condicional para alterar a animação de um sprite durante a execução do programa. O dinossauro se desloca para cima e, ao atingir determinada posição, sua animação é substituída por um pterodáctilo.

# Desafio a)

```javascript
var balloon = createSprite(200, 200);
balloon.setAnimation("balloon");
balloon.scale = 0.1;

var pop = createSprite(200,200);
pop.setAnimation("pop");
pop.visible = false;

function draw() {
  // Draw Background
  background("white");
  
  // Update Values
  balloon.scale = balloon.scale + 0.005;

  if (balloon.scale > 0.5) {
    balloon.visible = false;
    pop.visible = true;
  }

  // Draw Animations
  drawSprites();
}
```

Comentário: Neste desafio foi desenvolvido um efeito de crescimento de um balão utilizando a propriedade `scale`. Quando o balão atinge determinado tamanho, ele desaparece e é substituído por uma animação de estouro por meio da propriedade `visible`.

# Desafio b)

```javascript
background("grey");

var vampire = createSprite(50,200);
vampire.setAnimation("vampire");

var luis = createSprite(300,200);
luis.setAnimation("luis");
luis.scale = 0.8;

var garlic = createSprite(230,75);
garlic.setAnimation("garlic");
garlic.visible = false;
garlic.scale = 0.2;

var cruz = createSprite(230,75);
cruz.setAnimation("cruz");
cruz.visible = false;
cruz.scale = 0.4;

function draw() {
  background("grey");

  vampire.x = vampire.x + 1;

  if (vampire.x > 150) {
    garlic.visible = true;
    cruz.visible = true;
  }

  if (vampire.x > 280) {
    luis.setAnimation("blood");
  }

  if (vampire.x > 280) {
    textSize(20);
    fill("red");
    text("TODAY IS FRIDAY", 10, 30);
  }

  drawSprites();
}
```

Comentário: Neste desafio foram utilizados eventos condicionais para alterar o comportamento dos personagens de acordo com sua posição na tela. Também foram exploradas mudanças de animação, exibição de objetos ocultos e apresentação de mensagens em texto durante a execução da cena.
