template < class T > struct Billist
{
  T val;
  BilList< T > *next;
  BilList< T > *prev;
};

template < class T > class CircularBiList
{
private:
  BiList< T > *fake;
  size_t list_size;

public:
  CircularBiList();
  ~CircularBiList();

  CircularBiList(const CircularBiList &) = delete;
  CircularBiList &operator=(const CircularBiList &) = delete;

  void push_back(const T &value);
  void pop_back();
  bool is_empty() const noexcept;
  size_t size() const noexcept;
};

template < class T > CircularBiList< T >::CircularBiList()
{
  fake = new BiList< T >();
  fake->next = fake;
  fake->prev = fake;
  list_size = 0;
}

template < class T > CircularBiList< T >::~CircularBiList()
{
  BiList< T > *current = fake->next;

  while (current != fake) {
    BiList< T > *to_delete = current;
    current = current->next;
    delete to_delete;
  }

  delete fake;
}

template < class T > void CircularBiList< T >::push_back(const T &value)
{
  BiList< T > *new_node = new BiList< T >();
  new_node->val = value;

  new_node->next = fake;
  new_node->prev = fake->prev;

  fake->prev->next = new_node;
  fake->prev = new_node;

  ++list_size;
}

template < class T > void CircularBiList< T >::pop_back()
{
  if (is_empty()) {
    return;
  }

  BiList< T > *last_node = fake->prev;

  last_node->prev->next = fake;
  fake->prev = last_node->prev;

  delete last_node;
  --list_size;
}

template < class T > bool CircularBiList< T >::is_empty() const noexcept
{
  return list_size == 0;
}

template < class T > size_t CircularBiList< T >::size() const noexcept
{
  return list_size;
}
