.. SPDX-License-Identifier: GPL-3.0-or-later
.. SPDX-FileCopyrightText: Tobias Rehbein <tobias.rehbein@web.de>

.. include:: /global-include.rst

Help Style Guide
****************

The help texts displayed in the help browser are formatted as GitHub Flavored Markdown.
GitHub Flavored Markdown is documented here:
https://github.github.com/gfm/

This style guide is mostly meant for help text authors to ensure that we keep a consistent look and feel between authors.

.. note::
  Markdown support in the help browser is a relatively new feature and this style guide is most likely incomplete.
  We are expanding this style guide while we are going.


Headings
========

Most entries in the help browser are short and do not require any headings.
If headings are needed, we prefer `ATX Headings <https://github.github.com/gfm/#atx-headings>`_.
The largest heading that should be used is a third level heading (``### Heading``).

An example for the usage of headings can be found in the "Strategy and Tactics" help entry.


Unordered Lists / Bullet Points
===============================

The preferred marker for bullet points is the asterisk (``*``).
Although the dash (``-``) might feel more natural, programmatic generated help texts mainly use `*` and we aim to be consistent.

Links and References
====================

Links to External Resources
---------------------------

The help text can contain external links, like the "Strategy and Tactics" help, that links to a prettier formatted online version.

Links to other Help Topics
--------------------------

It is possible to link to other help topics using a custom URL scheme (``fch:<helptype>/<topic>``).
``topic`` is the title of the topic as displayed in the english help browser, with spaces replaced by ``%20``.
``helptype`` is a string describing the type of help.

Possible values for ``helptype`` are:

* ``Any``
* ``Text``
* ``Unit``
* ``Improvement``
* ``Wonder``
* ``Tech``
* ``Terrain``
* ``Extra``
* ``Goods``
* ``Specialist``
* ``Government``
* ``Ruleset``
* ``Tileset``
* ``Nations``
* ``Multiplier``
* ``Effect``

As an example, you link to the help about Mechanized Infantery, "Mech. Inf." in the help browser, using ``fch:Unit/Mech.%20Inf.``.
Look at the "Strategy and Tactics" help for further examples, it contains a variety of links to different topics.

Internal References in a Help Topic
-----------------------------------

Internal links to anchors in the help text itself are not supported.
Fortunately most help topics are rather short and work well without internal references.

The notable exception is the "Strategy and Tactics" help, where we use emphasized text to reference the different sections.

Admonitions
===========

Admonitions are not supported.
We emulate the effect by using emphasized all-uppercase emphasized admonition labels (e.g. ``*NOTE:*``)

Formulas and Literal Values
===========================

For inline formulas or literal values, we use code spans by wrapping them in backticks.
