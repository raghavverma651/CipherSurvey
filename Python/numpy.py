{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "%%time\n",
    "x=np.loadtxt('dataset.txt',dtype='str')\n",
    "import numpy as np\n",
    "valid_letters='abcdefghijklmnopqrstuvwxyz'\n",
    "user_key='keyword'\n",
    "key=''\n",
    "\n",
    "cipher=[]\n",
    "for char in user_key:\n",
    "    if char in valid_letters:\n",
    "            key+=char\n",
    "for char in valid_letters:\n",
    "    if char not in key:\n",
    "        key+=char\n",
    "        \n",
    "def encrypt(clear_text):\n",
    "    new_string=''\n",
    "    for char in clear_text:\n",
    "        if char in valid_letters:\n",
    "            new_string+=char\n",
    "    index_values=[valid_letters.index(char) for char in new_string]\n",
    "    return \"\".join(key[indexkey] for indexkey in index_values)\n",
    "Parallel(12)(delayed(encrypt)(str(word)) for word in np.nditer(x))"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.8.3"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 4
}
