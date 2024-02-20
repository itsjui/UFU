pais(alan, gustavo).
pais(alan, carla).
pais(alan, davi).
pais(davi, felipe).

maes(bianca, carla).
maes(bianca, davi).
maes(elise, felipe).

homem(alan).
homem(davi).
homem(gustavo).
homem(felipe).

mulher(bianca).
mulher(carla).
mulher(elise).

pai(A) :- homem(A), (pais(A, _); (A == alan, pais(alan, _))), !.

mae(B) :- mulher(B), (maes(B, _); (B == bianca, maes(bianca, _))), !.

homens(A, D) :- homem(A), homem(D), A \= D, !.

homem_sozinho(G) :- homem(G), G == gustavo, !.

mulheres(C) :- mulher(C), C == carla, !.

pai_sozinho(D) :- homem(D), \+ (pais(D, _), \+ D = davi), !.


% Consultas
% 1. Quem sao os pais?
?- pai(A).

% 2. Quem sao as maes?
?- mae(B).

% 3. Quem sao os homens?
?- homens(A, D).

% 4. Quem sao os homens?
?- homem_sozinho(G).

% 5. Quem sao as mulheres?
?- mulheres(C).

% 6. Quem sao os pais?
?- pai_sozinho(D).
