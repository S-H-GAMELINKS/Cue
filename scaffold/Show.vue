<template>
    <div class="container">
        <p><h1>Title: {{title}} </h1></p>
        <social-share></social-share>
        <p><h2>Content</h2></p>
        {{content}}
    </div>
</template>

<script>
import axios from 'axios';
import $ from 'jquery';

export default {
    data: function() {
        return {
            title: "",
            content: "",
        }
    },
    mounted: function() {
        this.getScaffold();
    },
    methods: {
        getScaffold: function() {
            const id = String(this.$route.path).replace(/\/scaffolds\//, '');

            axios.get('/api/posts/' + id).then((response) => {
                this.title = response.data.title;
                this.content = response.data.content;
            }, (error) => {
                alert(error);
            })
        }
    }
}
</script>