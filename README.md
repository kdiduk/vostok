## Vostok -- a 3D renderering library for Linux


### Building

```
$ mkdir build
$ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
$ make
```

### Setting up Emacs as a development environment

#### Setting up `clangd` to work with Emacs

##### Install `clangd` (Ubuntu)

```
$ sudo apt install clangd-15
$ sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-15 100
```

##### Installing and setting up `eglot` in Emacs

Install `eglot` using `MELPA`:

```
M-x package-install RET eglot RET
```

Then add the following in `~/.emacs`:

```
(require 'eglot)
(add-to-list 'eglot-server-programs '((c++-mode c-mode) "clangd"))
(add-hook 'c-mode-hook 'eglot-ensure)
(add-hook 'c++-mode-hook 'eglot-ensure)
```

To go to the symbol definition, the regular `Xref` commands can be used (`M-.`, `M-,`, etc).


#### Colored output in compilation buffer

By default Emacs will show escaped sequences in the compilation buffer when building the project with CMake.
To fix this, add the following to `~/.emacs`:

```
(require 'ansi-color)
(defun colorize-compilation-buffer ()
  (toggle-read-only)
  (ansi-color-apply-on-region compilation-filter-start (point))
  (toggle-read-only))
(add-hook 'compilation-filter-hook 'colorize-compilation-buffer)
```
