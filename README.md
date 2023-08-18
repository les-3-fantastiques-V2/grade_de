# PROJET

----
----
<br>

# REGLEMENTATION

# SOMMAIRE

<br>
<br>

[>> BRANCHE](#rules_branch)

[>> COMMIT](#rules_commit)

[>> FICHIER](#rules_file)

<br>
<br>

----

<br>
<br>

## Branche <a id="rules_branch"></a>

Construction :
```
{TYPE}/{NOM}
```

| Reference | Contenu | Obligatoire |
|-|-|-|
| {TYPE} | [Voir tableau type](#table_type_branch) | OUI |
| {NOM} | Nom décrivant la branche | OUI |

<br>
<br>

Type<a id="table_type_branch"></a>

| Terme | Utilisation | Exemple |
|-|-|-|
| ADD | Ajout de contenu | ADD/start-loader |
| FIX | Fix de problèmes | FIX/generation-problem |
| REFACTO | Restructuration du code | REFACTO/using-correct-type |


<br>
<br>

Langue : Anglais

<br>
<br>

----

<br>
<br>

## COMMITS <a id="rules_commit"></a>

Construction :
```
[{TYPE}] : {SOMMAIRE}
>> {DESCRIPTION}
```

| Reference | Contenu | Obligatoire |
|-|-|-|
| {TYPE} | [Voir tableau type](#table_type_commit) | OUI |
| {SOMMAIRE} | Petit sommaire du commit | OUI |
| {DESCRIPTION} | Description complète du commit | NON |

<br>
<br>

Type<a id="table_type_commit"></a>

| Terme | Utilisation | Exemple |
|-|-|-|
| ADD | Ajout de contenu | [ADD] : Loader at start |
| DEL | Suppression de contenu | [DEL] : Old Feature |
| FIX | Fix de problèmes | [FIX] : Generation error |
| REFACTO | Restructuration du code | [REFACTO] : Using correct type |
| MOD | Modification d'un contenu | [MOD] : Rules of README |
| CLEAN | Nettoyage d'un contenu | [CLEAN] : Unused old files |


<br>
<br>

Langue : Anglais

<br>
<br>


Exemple de Commits :
```
[ADD] : Project Setup
>> Adding README and .gitignore files
```

<br>
<br>

----

<br>
<br>


## FICHIER <a id="rules_file"></a>

Modèle de nom des fichiers / dossier : camelCase
> camelCase :
> - Pas d'espace
> - Première lettre en minuscule
> - Première lettre de chaque mot en majuscule
> - Pas d'accent
>
> Exemple : nomDeFichier.c

Modèle de nom des fonctions : camelCase
> camelCase :
> - Pas d'espace
> - Première lettre en minuscule
> - Première lettre de chaque mot en majuscule
> - Pas d'accent
>
> Exemple : nomDeFonction

Modèle de nom des structures : PascalCase
> PascalCase :
> - Pas d'espace
> - Première lettre en minuscule
> - Pas d'accent
>
> Exemple : NomDeStructure


<br>
<br>

----

<br>
<br>
