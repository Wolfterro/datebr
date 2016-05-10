# datebr
#### Hora e Data em Formato Padrão do Brasil

### Descrição:

###### Este é um simples programa escrito em C que mostra ao usuário a data e a hora atual em formato padrão do Brasil.
###### O formato padrão para data é "dd/mm/yyyy" e o formato padrão para hora é "hh/mm/ss".
###### O programa também mostra o dia da semana e se o horário atual é comum ou horário de verão.
###### É possível também usar alguns argumentos para controlar o que o programa irá mostrar:

      Uso: datebr [Argumento]
      
      Argumentos:
      -h   ou --help:                   Mostra a tela de ajuda
      -d   ou --date:                   Mostra apenas a data atual
      -t   ou --time:                   Mostra apenas a hora atual
      -dst ou --daylight-saving-time    Mostra apenas o tipo de horário atual

### Instalação:

###### Você poderá compilar o programa em seu sistema através do comando abaixo:

      git clone https://github.com/Wolfterro/datebr.git
      cd datebr/
      sudo make install
      datebr [Argumento]
