# 🌌 Fract'ol

Un générateur de fractales interactif développé en C avec la bibliothèque MiniLibX. Ce projet fait partie du cursus de l'École 42 et permet d'explorer la beauté mathématique des ensembles de Mandelbrot et de Julia.

![Fract'ol Preview](https://via.placeholder.com/800x400/0D1117/58A6FF?text=Fract%27ol+Preview)

## 📋 Table des matières

- [À propos](#à-propos)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Contrôles](#contrôles)
- [Exemples](#exemples)
- [Structure du projet](#structure-du-projet)
- [Technologies utilisées](#technologies-utilisées)
- [Algorithmes](#algorithmes)
- [Auteur](#auteur)

## 🔍 À propos

Fract'ol est un programme qui génère et affiche des fractales mathématiques en temps réel. Les fractales sont des objets géométriques infiniment complexes qui révèlent des détails similaires à toutes les échelles de zoom.

### Fractales supportées :
- **Mandelbrot** : L'ensemble classique découvert par Benoit Mandelbrot
- **Julia** : Ensembles de Julia avec paramètres personnalisables

## ✨ Fonctionnalités

- 🎨 **Rendu en temps réel** des fractales
- 🔍 **Zoom infini** avec la molette de la souris
- 🎮 **Navigation fluide** avec les touches fléchées
- 🌈 **Palettes de couleurs multiples** (4 schémas différents)
- ⚙️ **Paramètres Julia configurables** via ligne de commande
- 🎯 **Interaction souris** pour modifier les paramètres Julia en temps réel
- 📊 **Contrôle des itérations** pour ajuster la précision

## 🚀 Installation

### Prérequis

- GCC ou Clang
- Make
- X11 development libraries
- XShm extension

#### Sur Ubuntu/Debian :
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

#### Sur macOS :
```bash
brew install xquartz
# Redémarrer après l'installation
```

### Compilation

```bash
git clone https://github.com/votre-username/fractol.git
cd fractol
make
```

## 💻 Utilisation

### Syntaxe de base

```bash
# Mandelbrot
./fractol M

# Julia (paramètres par défaut)
./fractol J

# Julia avec paramètres personnalisés
./fractol J [real] [imaginary]
```

### Exemples d'utilisation

```bash
# Ensemble de Mandelbrot
./fractol M

# Julia avec différents paramètres
./fractol J 0.25 -0.55
./fractol J -0.7 0.27015
./fractol J -0.4 0.6
./fractol J 0.285 0.01
```

## 🎮 Contrôles

| Action | Contrôle |
|--------|----------|
| **Navigation** | Touches fléchées |
| **Zoom avant** | Molette souris vers le haut |
| **Zoom arrière** | Molette souris vers le bas |
| **Plus d'itérations** | `+` |
| **Moins d'itérations** | `-` |
| **Changer de palette** | `Espace` |
| **Julia interactif** | Clic gauche (fractales Julia) |
| **Quitter** | `ESC` |

## 🎨 Exemples visuels

### Ensemble de Mandelbrot
```bash
./fractol M
```
Explorez l'ensemble de Mandelbrot classique avec ses détails fractals infinis.

### Ensembles de Julia
```bash
# Julia "Dragon"
./fractol J -0.7 0.27015

# Julia "Rabbit"
./fractol J -0.123 0.745

# Julia "Lightning"
./fractol J -0.8 0.156
```

## 📁 Structure du projet

```
fractol/
├── src/
│   ├── main.c          # Point d'entrée et initialisation
│   ├── render.c        # Algorithmes de rendu des fractales
│   ├── events.c        # Gestion des événements (clavier/souris)
│   ├── color.c         # Palettes de couleurs
│   ├── utils.c         # Fonctions utilitaires
│   ├── parse.c         # Parsing des arguments
│   ├── error.c         # Gestion des erreurs
│   └── exit.c          # Nettoyage et sortie
├── include/
│   ├── fractol.h       # Header principal
│   └── defines.h       # Constantes et définitions
├── libft/              # Bibliothèque personnelle
├── minilibx-linux/     # Bibliothèque graphique
└── Makefile
```

## 🛠️ Technologies utilisées

- **Langage** : C
- **Bibliothèque graphique** : [MiniLibX](https://github.com/42Paris/minilibx-linux)
- **Bibliothèque personnelle** : [Libft](libft/)
- **Mathématiques** : Nombres complexes, algorithmes d'échappement
- **Système** : X11/XQuartz pour l'affichage

## 🧮 Algorithmes

### Ensemble de Mandelbrot
Pour chaque point `c` du plan complexe :
```
z₀ = 0
zₙ₊₁ = zₙ² + c
```
Le point appartient à l'ensemble si la suite reste bornée.

### Ensembles de Julia
Pour une constante complexe `c` fixée :
```
z₀ = point_du_plan
zₙ₊₁ = zₙ² + c
```

### Optimisations
- **Calcul vectorisé** pour améliorer les performances
- **Zoom centré sur la souris** pour une navigation intuitive
- **Rendu adaptatif** selon le niveau de zoom

## 🎨 Palettes de couleurs

Le projet inclut 4 schémas de couleurs différents :
1. **Électrique** : Bleus et violets vibrants
2. **Feu** : Dégradés de rouge, orange et jaune
3. **Océan** : Tons bleus et verts
4. **Psychédélique** : Couleurs vives et contrastées

## 🚀 Fonctionnalités avancées

- **Zoom intelligent** : Conservation du point central lors du zoom
- **Julia interactif** : Modification en temps réel des paramètres
- **Gestion mémoire optimisée** : Aucune fuite mémoire
- **Interface utilisateur** : Guide d'aide intégré

## 🐛 Résolution de problèmes

### Problèmes courants

**Erreur de compilation MiniLibX :**
```bash
cd minilibx-linux
./configure
make
```

**Problème d'affichage sur macOS :**
Assurez-vous que XQuartz est installé et redémarrez votre session.

## 📚 Ressources utiles

- [Ensemble de Mandelbrot - Wikipedia](https://fr.wikipedia.org/wiki/Ensemble_de_Mandelbrot)
- [Ensemble de Julia - Wikipedia](https://fr.wikipedia.org/wiki/Ensemble_de_Julia)
- [Documentation MiniLibX](https://github.com/42Paris/minilibx-linux)

## 👨‍💻 Auteur

**rwassim** - Étudiant à l'École 42

- GitHub: [@rwassim](https://github.com/mossfreestyle)
- Email: rwassim@student.42.fr

## 📄 Licence

Ce projet est développé dans le cadre du cursus de l'École 42. Code disponible pour l'apprentissage et la référence.

---

⭐ **N'hésitez pas à laisser une étoile si ce projet vous a été utile !**

*Développé avec ❤️ à l'École 42*
