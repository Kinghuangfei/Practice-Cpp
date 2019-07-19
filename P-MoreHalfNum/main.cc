int main () {
  int num , which;
  while ( cin >> num  ) {
    string query , in;
    vector<string> bro , dir;
    while ( num--  ) {
      cin >> in;
      dir.push_back (in);

    }
    sort (dir.begin () , dir.end ());
    cin >> query;
    cin >> which;
    for ( auto e : dir  ) {
      if ( isBro (query , e)  )
        bro.push_back (e);

    }
    size_t size = bro.size ();
    cout << size << endl;
    if ( which <= size  )
      cout << bro [which - 1] << endl;

  }
  return 0;

}

