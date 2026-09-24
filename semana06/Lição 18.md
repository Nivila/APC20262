# Projeto Final

```javascript
// variáveis
var score = 0;
var health = 100;
var level = 1;
var speed = 5;
var gameStarted = false;
var bossHealth = 150;
var bossTimer = 0;
var bossStarted = false;
var bossAttackTime = 60;
var gameOver = false;
var gameWon = false;
var hurtTimer = 0;
var bossShake = 0;
var bossShakeSide = 1;

// cenário
var gameBackground = createSprite(200, 200);
gameBackground.setAnimation("background_vintage");

// personagem
var singer = createSprite(75, 242);
singer.setAnimation("singer_run");
singer.scale = 2.4;

// bolinha
var ball = createSprite(-100, 242, 12, 12);
ball.shapeColor = "lightblue";
ball.visible = false;

// nota prateada
var musicSilver = createSprite(500, 250);
musicSilver.setAnimation("music_silver");
musicSilver.scale = 0.18;

// disco quebrado
var brokenRecord = createSprite(800, 250);
brokenRecord.setAnimation("broken_record");
brokenRecord.scale = 0.5;

// outro disco quebrado
var brokenRecord2 = createSprite(650, 250);
brokenRecord2.setAnimation("broken_record");
brokenRecord2.scale = 0.5;

// nota dourada
var musicGold = createSprite(1100, 250);
musicGold.setAnimation("music_gold");
musicGold.scale = 0.18;

// amplificador
var guitarSpeaker = createSprite(1400, 250);
guitarSpeaker.setAnimation("guitar_speaker");
guitarSpeaker.scale = 0.1;

// outro amplificador
var guitarSpeaker2 = createSprite(1250, 250);
guitarSpeaker2.setAnimation("guitar_speaker");
guitarSpeaker2.scale = 0.1;

// nota bônus
var musicBonus = createSprite(1700, 250);
musicBonus.setAnimation("music_bonus");
musicBonus.scale = 0.18;

// piano
var piano = createSprite(2000, 250);
piano.setAnimation("piano");
piano.scale = 0.2;

// outro piano
var piano2 = createSprite(1850, 250);
piano2.setAnimation("piano");
piano2.scale = 0.2;

// coração
var heart = createSprite(2300, 250);
heart.setAnimation("heart");
heart.scale = 0.07;

// chefão
var boss = createSprite(500, 220);
boss.setAnimation("boss");
boss.scale = 0.25;
boss.visible = false;

// nota perigosa
var musicDark = createSprite(500, 250);
musicDark.setAnimation("music_dark");
musicDark.scale = 0.12;
musicDark.visible = false;


// jogo
function draw() {
  background("black");

  chooseBackground();

  gameBackground.visible = true;
  drawSprite(gameBackground);
  gameBackground.visible = false;

  drawStage();

  userControls();
  objectMovement();
  resetObjects();

  checkCollectibles();
  checkObstacles();
  checkBallHits();
  bossFight();
  checkGame();

  drawSprites();
  displayBoard();

  if (gameStarted == false) {
    if (gameOver == false) {
      if (gameWon == false) {
        showInstructions();
      }
    }
  }

  if (gameOver == true) {
    showGameOver();
  }

  if (gameWon == true) {
    showWin();
  }
}


// controles
function userControls() {
  if (gameOver == false) {
    if (gameWon == false) {
      startGame();
      singerMovement();
      ballMovement();
    }
  }
}


// começa o jogo
function startGame() {
  if (keyDown("up")) {
    gameStarted = true;
  }

  if (keyDown("space")) {
    gameStarted = true;
  }
}


// movimento da personagem
function singerMovement() {

  // tempo da animação de dano
  if (hurtTimer > 0) {
    hurtTimer = hurtTimer - 1;
  }

  // pula com a seta para cima
  if (keyDown("up")) {
    if (singer.y >= 242) {
      singer.velocityY = -10;

      if (hurtTimer == 0) {
        singer.setAnimation("singer_jump");
      }
    }
  }

  // gravidade
  singer.velocityY = singer.velocityY + 0.6;

  // volta para o chão
  if (singer.y > 242) {
    singer.y = 242;
    singer.velocityY = 0;

    if (hurtTimer == 0) {
      singer.setAnimation("singer_run");
    }
  }

  // personagem machucada
  if (hurtTimer > 0) {
    singer.setAnimation("singer_hurt");
  }

  // volta para animação do pulo
  if (hurtTimer == 0) {
    if (singer.y < 242) {
      singer.setAnimation("singer_jump");
    }
  }
}


// movimento da bolinha
function ballMovement() {
  // lança com espaço
  if (keyWentDown("space")) {
    if (ball.visible == false) {
      ball.x = singer.x + 30;
      ball.y = singer.y;
      ball.velocityX = 8;
      ball.visible = true;
    }
  }

  // esconde quando sai da tela
  if (ball.x > 420) {
    ball.x = -100;
    ball.velocityX = 0;
    ball.visible = false;
  }
}


// movimento dos objetos
function objectMovement() {
  if (gameStarted == true) {
    if (level < 6) {
      musicSilver.velocityX = -speed;
      musicGold.velocityX = -speed;
      musicBonus.velocityX = -speed;
      heart.velocityX = -speed;

      brokenRecord.velocityX = -speed;
      brokenRecord2.velocityX = -speed - 1;

      guitarSpeaker.velocityX = -speed;
      guitarSpeaker2.velocityX = -speed - 1;

      piano.velocityX = -speed;
      piano2.velocityX = -speed - 2;
    }

    if (level == 6) {
      musicSilver.velocityX = 0;
      musicGold.velocityX = 0;
      musicBonus.velocityX = 0;
      heart.velocityX = 0;

      brokenRecord.velocityX = 0;
      brokenRecord2.velocityX = 0;

      guitarSpeaker.velocityX = 0;
      guitarSpeaker2.velocityX = 0;

      piano.velocityX = 0;
      piano2.velocityX = 0;
    }
  }

  if (gameStarted == false) {
    musicSilver.velocityX = 0;
    musicGold.velocityX = 0;
    musicBonus.velocityX = 0;
    heart.velocityX = 0;

    brokenRecord.velocityX = 0;
    brokenRecord2.velocityX = 0;

    guitarSpeaker.velocityX = 0;
    guitarSpeaker2.velocityX = 0;

    piano.velocityX = 0;
    piano2.velocityX = 0;
  }
}


// objetos voltam para a direita
function resetObjects() {
  if (musicSilver.x < -100) {
    musicSilver.x = musicSilver.x + 2400;
  }

  if (brokenRecord.x < -100) {
    brokenRecord.x = brokenRecord.x + 2400;
  }

  if (brokenRecord2.x < -100) {
    brokenRecord2.x = brokenRecord2.x + 2400;
  }

  if (musicGold.x < -100) {
    musicGold.x = musicGold.x + 2400;
  }

  if (guitarSpeaker.x < -100) {
    guitarSpeaker.x = guitarSpeaker.x + 2400;
  }

  if (guitarSpeaker2.x < -100) {
    guitarSpeaker2.x = guitarSpeaker2.x + 2400;
  }

  if (musicBonus.x < -100) {
    musicBonus.x = musicBonus.x + 2400;
  }

  if (piano.x < -100) {
    piano.x = piano.x + 2400;
  }

  if (piano2.x < -100) {
    piano2.x = piano2.x + 2400;
  }

  if (heart.x < -100) {
    heart.x = heart.x + 2400;
  }
}


// coleta os itens
function checkCollectibles() {
  if (level < 6) {
    if (singer.isTouching(musicSilver)) {
      score = score + 10;
      musicSilver.x = musicSilver.x + 2400;
    }

    if (singer.isTouching(musicGold)) {
      score = score + 20;
      musicGold.x = musicGold.x + 2400;
    }

    if (singer.isTouching(musicBonus)) {
      score = score + 30;
      musicBonus.x = musicBonus.x + 2400;
    }

    if (singer.isTouching(heart)) {
      health = health + 20;

      if (health > 100) {
        health = 100;
      }

      heart.x = heart.x + 2400;
    }
  }
}


// colisão com os obstáculos
function checkObstacles() {
  if (level < 6) {

    if (singer.isTouching(brokenRecord)) {
      health = health - 10;
      hurtTimer = 15;
      singer.setAnimation("singer_hurt");
      brokenRecord.x = brokenRecord.x + 2400;
    }

    if (singer.isTouching(brokenRecord2)) {
      health = health - 10;
      hurtTimer = 15;
      singer.setAnimation("singer_hurt");
      brokenRecord2.x = brokenRecord2.x + 2400;
    }

    if (singer.isTouching(guitarSpeaker)) {
      health = health - 15;
      hurtTimer = 15;
      singer.setAnimation("singer_hurt");
      guitarSpeaker.x = guitarSpeaker.x + 2400;
    }

    if (singer.isTouching(guitarSpeaker2)) {
      health = health - 15;
      hurtTimer = 15;
      singer.setAnimation("singer_hurt");
      guitarSpeaker2.x = guitarSpeaker2.x + 2400;
    }

    if (singer.isTouching(piano)) {
      health = health - 20;
      hurtTimer = 15;
      singer.setAnimation("singer_hurt");
      piano.x = piano.x + 2400;
    }

    if (singer.isTouching(piano2)) {
      health = health - 20;
      hurtTimer = 15;
      singer.setAnimation("singer_hurt");
      piano2.x = piano2.x + 2400;
    }
  }

  if (health < 0) {
    health = 0;
  }
}


// bolinha acerta os obstáculos
function checkBallHits() {
  if (level < 6) {

    if (ball.isTouching(brokenRecord)) {
      brokenRecord.x = brokenRecord.x + 2400;
      score = score + 5;

      ball.x = -100;
      ball.velocityX = 0;
      ball.visible = false;
    }

    if (ball.isTouching(brokenRecord2)) {
      brokenRecord2.x = brokenRecord2.x + 2400;
      score = score + 5;

      ball.x = -100;
      ball.velocityX = 0;
      ball.visible = false;
    }

    if (ball.isTouching(guitarSpeaker)) {
      guitarSpeaker.x = guitarSpeaker.x + 2400;
      score = score + 5;

      ball.x = -100;
      ball.velocityX = 0;
      ball.visible = false;
    }

    if (ball.isTouching(guitarSpeaker2)) {
      guitarSpeaker2.x = guitarSpeaker2.x + 2400;
      score = score + 5;

      ball.x = -100;
      ball.velocityX = 0;
      ball.visible = false;
    }

    if (ball.isTouching(piano)) {
      piano.x = piano.x + 2400;
      score = score + 5;

      ball.x = -100;
      ball.velocityX = 0;
      ball.visible = false;
    }

    if (ball.isTouching(piano2)) {
      piano2.x = piano2.x + 2400;
      score = score + 5;

      ball.x = -100;
      ball.velocityX = 0;
      ball.visible = false;
    }
  }
}


// batalha com o chefão
function bossFight() {
  if (level == 6) {
    if (gameOver == false) {
      if (gameWon == false) {

        // começa a batalha
        if (bossStarted == false) {
          bossStarted = true;
          health = 100;
          bossTimer = 0;
        }

        boss.visible = true;
        boss.x = 330;
        boss.y = 220;

        // vibração do chefão
        if (bossShake > 0) {
          boss.x = 330 + bossShakeSide * 5;
          bossShakeSide = bossShakeSide * -1;
          bossShake = bossShake - 1;
        }

        // esconde os objetos das outras fases
        musicSilver.visible = false;
        musicGold.visible = false;
        musicBonus.visible = false;
        heart.visible = false;

        brokenRecord.visible = false;
        brokenRecord2.visible = false;

        guitarSpeaker.visible = false;
        guitarSpeaker2.visible = false;

        piano.visible = false;
        piano2.visible = false;

        // velocidade dos ataques do chefão
        bossAttackTime = 60;

        if (bossHealth <= 100) {
          bossAttackTime = 45;
        }

        if (bossHealth <= 50) {
          bossAttackTime = 30;
        }

        bossTimer = bossTimer + 1;

        // chefão lança a nota
        if (bossTimer > bossAttackTime) {
          if (musicDark.visible == false) {
            musicDark.x = 300;
            musicDark.y = 250;
            musicDark.velocityX = -5;

            if (bossHealth <= 100) {
              musicDark.velocityX = -6;
            }

            if (bossHealth <= 50) {
              musicDark.velocityX = -7;
            }

            musicDark.visible = true;
            bossTimer = 0;
          }
        }

        // nota perigosa saiu da tela
        if (musicDark.x < -20) {
          musicDark.velocityX = 0;
          musicDark.visible = false;
          musicDark.x = 500;
          musicDark.y = 250;
          bossTimer = 20;
        }

        // nota perigosa acerta a personagem
        if (musicDark.visible == true) {
          if (singer.isTouching(musicDark)) {
            health = health - 10;

            hurtTimer = 15;
            singer.setAnimation("singer_hurt");

            musicDark.velocityX = 0;
            musicDark.visible = false;
            musicDark.x = 500;
            musicDark.y = 250;
            bossTimer = 20;
          }
        }

        // bolinha acerta o chefão
        if (ball.visible == true) {
          if (ball.isTouching(boss)) {
            bossHealth = bossHealth - 10;

            // chefão vibra quando é atingido
            bossShake = 12;

            ball.x = -100;
            ball.velocityX = 0;
            ball.visible = false;
          }
        }

        // chefão derrotado
        if (bossHealth <= 0) {
          bossHealth = 0;
          boss.visible = false;

          musicDark.visible = false;
          musicDark.velocityX = 0;

          gameWon = true;
          gameStarted = false;
        }
      }
    }
  }
}


// verifica o fim do jogo
function checkGame() {
  if (gameWon == false) {
    if (health <= 0) {
      health = 0;
      gameOver = true;
      gameStarted = false;

      boss.visible = false;

      musicDark.velocityX = 0;
      musicDark.visible = false;

      ball.velocityX = 0;
      ball.visible = false;
    }
  }
}


// troca o cenário
function chooseBackground() {
  if (score < 100) {
    gameBackground.setAnimation("background_vintage");
    level = 1;
    speed = 6;
  }

  if (score >= 100) {
    gameBackground.setAnimation("background_garden");
    level = 2;
    speed = 8;
  }

  if (score >= 250) {
    gameBackground.setAnimation("background_neon");
    level = 3;
    speed = 10;
  }

  if (score >= 450) {
    gameBackground.setAnimation("background_space");
    level = 4;
    speed = 12;
  }

  if (score >= 700) {
    gameBackground.setAnimation("background_final");
    level = 5;
    speed = 14;
  }

  if (score >= 1000) {
    gameBackground.setAnimation("background_boss");
    level = 6;
    speed = 14;
  }
}


// desenha o palco
function drawStage() {
  stroke("black");
  strokeWeight(4);
  fill("dimgray");
  rect(0, 280, 400, 120);

  stroke("white");
  strokeWeight(3);
  line(0, 280, 400, 280);

  stroke("gray");
  strokeWeight(2);
  line(0, 320, 400, 320);
  line(0, 360, 400, 360);

  // caixa esquerda
  stroke("black");
  strokeWeight(3);
  fill("darkgray");
  rect(10, 295, 70, 95);

  fill("black");
  ellipse(45, 320, 30, 30);
  ellipse(45, 365, 45, 45);

  fill("gray");
  ellipse(45, 320, 14, 14);
  ellipse(45, 365, 22, 22);

  // caixa direita
  stroke("black");
  strokeWeight(3);
  fill("darkgray");
  rect(320, 295, 70, 95);

  fill("black");
  ellipse(355, 320, 30, 30);
  ellipse(355, 365, 45, 45);

  fill("gray");
  ellipse(355, 320, 14, 14);
  ellipse(355, 365, 22, 22);

  // enfeites
  noStroke();

  fill("orchid");
  ellipse(110, 320, 14, 14);

  fill("gold");
  ellipse(140, 365, 14, 14);

  fill("deepskyblue");
  ellipse(260, 320, 14, 14);

  fill("hotpink");
  ellipse(290, 365, 14, 14);

  fill("white");
  textSize(22);
  text("♪", 90, 390);
  text("♫", 190, 345);
  text("♪", 290, 390);
}


// instruções
function showInstructions() {
  stroke("black");
  strokeWeight(3);
  fill("white");
  rect(65, 95, 285, 100);

  noStroke();
  fill("black");
  textSize(16);

  text("SETA PARA CIMA: PULAR", 95, 125);
  text("ESPAÇO: LANÇAR BOLINHA", 85, 155);
  text("APERTE UMA TECLA PARA COMEÇAR", 75, 183);
}


// game over
function showGameOver() {
  stroke("black");
  strokeWeight(3);
  fill("white");
  rect(80, 125, 240, 90);

  noStroke();
  fill("black");
  textSize(30);
  text("GAME OVER", 110, 175);

  textSize(14);
  text("Score: " + score, 165, 200);
}


// vitória
function showWin() {
  stroke("black");
  strokeWeight(3);
  fill("white");
  rect(65, 120, 270, 100);

  noStroke();
  fill("black");
  textSize(27);
  text("VOCÊ VENCEU!", 95, 170);

  textSize(14);
  text("Chefão derrotado!", 135, 200);
}


// placar
function displayBoard() {
  fill("white");
  stroke("black");
  strokeWeight(3);
  textSize(18);

  text("Score: " + score, 15, 25);
  text("Health: " + health, 15, 50);
  text("Level: " + level, 15, 75);

  if (level == 6) {
    text("Boss: " + bossHealth, 275, 25);
  }

  noStroke();
}
```

Comentário: Nesta atividade foi desenvolvido o projeto final no Game Lab, reunindo vários dos conteúdos trabalhados durante as lições anteriores. O jogo possui movimentação da personagem, salto, lançamento de bolinha, coleta de itens, obstáculos, pontuação, sistema de vida, mudança de níveis e cenários, aumento de dificuldade e uma batalha final contra um chefão.

Durante o desenvolvimento foram utilizadas funções para organizar as diferentes partes do jogo, estruturas condicionais para controlar os acontecimentos, colisões entre sprites, velocidades, gravidade, animações e variáveis para acompanhar a pontuação, vida e progresso do jogador.

Minha experiência com essa atividade foi muito bacana, principalmente porque eu nunca tinha tido tanto contato direto com programação. Tenho amigos que desenvolvem jogos e antes eu costumava apenas testar os projetos deles. Dessa vez, mesmo desenvolvendo um jogo simples, pude enxergar esse processo de outro ângulo e entender um pouco melhor como funciona a construção de um jogo.

A atividade também me deu mais confiança para continuar aprendendo programação. Antes de começar, JavaScript parecia algo muito mais difícil, mas a forma como as atividades foram divididas em etapas tornou o aprendizado mais intuitivo. Apesar de ser um projeto extenso, consegui perceber minha evolução ao longo das lições e fiquei orgulhosa do resultado final.

Também gostei bastante de trabalhar com coordenadas, posicionamento dos sprites e pixel art. Já tive contato anteriormente com código G por trabalhar com máquinas e usinagem, então a lógica de coordenadas não era completamente nova para mim. Isso facilitou meu entendimento de algumas partes do Game Lab e tornou a experiência ainda mais interessante.

No final, essa atividade me mostrou que programação é uma área na qual eu consigo me aprofundar mais. Esse conhecimento também pode ser importante para minha área de formação, principalmente em aplicações relacionadas à energia, automação e gestão energética. Espero conseguir me adaptar às próximas linguagens trabalhadas em sala tão bem quanto consegui me adaptar ao JavaScript.
