.. SPDX-License-Identifier: GPL-3.0-or-later
.. SPDX-FileCopyrightText: Freeciv21 and Freeciv Contributors
.. SPDX-FileCopyrightText: James Robertson <jwrober@gmail.com>
.. SPDX-FileCopyrightText: Louis Moureaux <m_louis30@yahoo.com>

.. include:: /global-include.rst

Installing Freeciv21
********************

The developers of Freeciv21 provide pre-compiled binaries and installation packages for tagged releases. They
can be found on the Longturn GitHub Repository for Freeciv21 at
https://github.com/longturn/freeciv21/releases. The Longturn community provides binary packages for
Debian-based Linux distros (Debian, Ubuntu, Mint, etc.), Microsoft Windows\ |reg| (32 and 64-bit), and Apple
macOS\ |reg|. If you are an Arch Linux user, you can find Freeciv21 in the AUR at
https://aur.archlinux.org/packages/freeciv21.

Windows
=======

For more information on using the Windows Installer package, you can read about it at :doc:`windows-install`.

Debian Linux
============

To install the Debian package, use the ``apt`` command with elevated privileges like this:

.. code-block:: sh

  $ sudo apt install ./freeciv21_*_amd64.deb


macOS
=====

To install the macOS ``.dmg`` package, you start by double-clicking the file to mount it in Finder. Drag the
game to your Applications folder, or a place of your choosing. When finished, unmount the package.

.. note::
  In newer versions of macOS, you may get an error message when trying to mount the package: "Freeciv21.app is
  damaged and can't be opened." You will need to adjust the security settings on your computer. Here are some
  website links to help:

  * https://appletoolbox.com/app-is-damaged-cannot-be-opened-mac/
  * https://support.apple.com/guide/mac-help/open-an-app-by-overriding-security-settings-mh40617/15.0/mac/15.0
