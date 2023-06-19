;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

((c++-mode . ((c-file-style . "stroustrup")
	      (indent-tabs-mode . nil)
	      (c-file-offsets . ((arglist-intro . ++)
				 (arglist-cont-nonempty . ++)
				 (arglist-close . 0)
				 (brace-list-intro . 0)
				 (innamespace . 0)
				 (statement-cont . ++)
				 (inline-open . 0)))))
 (nil . ((projectile-tags-command . "ctags-universal -eR src; ctags-universal -aeR include; ctags-universal -aeR build/_deps/sdl-src/include/; ctags-universal -aeR build/_deps/sdl-src/src/")))
 )
